<?php
	/**
	* user class
	*/
	class User
	{
		private $user_id;
		private $user_name;
		private $GML;
		private $pw;
		function __construct($id,$name,$gml,$pw){
      		$this->user_id=$id;
      		$this->user_name=$name;
      		$this->GML=$gml;
      		$this->pw=$pw;
   		}
		function getUserID(){
			return $this->user_id;
		}
		function getUserName(){
			return $this->user_name;
		}
		function getGML(){
			return $this->GML;
		}
		function getPW(){
			return $this->pw;
		}
		function searchAllBookInfo($key){		//搜尋所有書籍資訊
			$sql = "SELECT * FROM book ";
  			if($key!=""){
    			$sql =$sql."WHERE book_id LIKE '%$key%' OR ".
                    	   "book_name LIKE '%$key%' OR ".
                     	   "publishing_house LIKE '%$key%' OR ".
                     	   "author LIKE '%$key%'";
  			}
  			$sql= $sql." ORDER BY date DESC";
			return $sql;
		}
		function seachAllBookMyself($keyMyBook){		//搜尋自己借書資訊
			$sql="SELECT * FROM book WHERE book.book_id in(
	      			SELECT book_id FROM borrowed_book WHERE book_id=borrowed_book.book_id AND user_id='".$this->user_id."')";
			if($keyMyBook!=""){
				$sql=$sql." AND (book.book_id LIKE '%$keyMyBook%' OR ".
                     "book.book_name LIKE '%$keyMyBook%' OR ".
                     "book.publishing_house LIKE '%$keyMyBook%' OR ".
                     "book.author LIKE '%$keyMyBook%')";
			}
			$sql= $sql." ORDER BY date DESC";
			return $sql;
		}
	}
	/**
	* DBMer
	*/
	class Librarian extends User
	{
		
		function __construct($id,$name,$gml,$pw)
		{
			 parent::__construct($id,$name,$gml,$pw);
		}
		function searchAllBorrowedBook($key){
			$sql="SELECT * FROM borrowed_book ";
			if($key!=""){
    			$sql =$sql."WHERE book_id LIKE '%$key%' OR ".
                    	   "user_id LIKE '%$key%'";
  			}
  			$sql= $sql." ORDER BY date DESC";
			return $sql;
		}
		function checkUser($user_id){
			$sql="SELECT count(user_id) FROM user WHERE user_id='$user_id'";
			return $sql;
		}
		function checkBook($book_id){
			$sql="SELECT count(book_id) FROM book WHERE book_id='$book_id'";
			return $sql;
		}
		function checkBookState($book_id){
			$sql="SELECT state FROM book WHERE book_id='$book_id'";
			return $sql;
		}
		function returnBook($book_id){
			$sql="DELETE FROM borrowed_book WHERE book_id='$book_id'";
			return $sql;
		}
		function assisBorrow($user_id,$book_id,$date,$returnDate){
			$sql="INSERT INTO borrowed_book VALUES('$book_id','$user_id','$date','$returnDate')";
			return $sql;
		}
		function changeBookStato0($book_id){
			$sql="UPDATE book SET state=0 WHERE book_id='$book_id'";
			return $sql;
		}
		function changeBookStato1($book_id){
			$sql="UPDATE book SET state=1 WHERE book_id='$book_id'";
			return $sql;
		}



	}

	class DBMer extends User
	{
		
		function __construct($id,$name,$gml,$pw)
		{
			 parent::__construct($id,$name,$gml,$pw);
		}
		function seachAllUser($keyAllUser){
			$sql = "SELECT * FROM user ";
  			if($keyAllUser!=""){
    			$sql =$sql."WHERE user_id LIKE '%$keyAllUser%' OR ".
                    	   "user_name LIKE '%$keyAllUser%'";
  			}
  			$sql= $sql." ORDER BY user_id ASC";
			return $sql;
		}
		function seachAllBook($keyAllBook){
			$sql = "SELECT * FROM book ";
  			if($keyAllBook!=""){
    			$sql =$sql."WHERE book_id LIKE '%$keyAllBook%' OR ".
                    	   "user_name LIKE '%$keyAllBook%' OR ".
                    	   "GML LIKE '%$keyAllBook%'";
  			}
  			$sql= $sql." ORDER BY book_id ASC";
			return $sql;
		}
		function deleteUser($user_id){
			$sql="DELETE FROM user WHERE user_id='$user_id'";
			return $sql;
		}
		function deleteBook($book_id){
			$sql="DELETE FROM book WHERE book_id='$book_id'";
			return $sql;
		}
		function modifyUser($user_id,$user_name,$GML,$pw){
			$sql="UPDATE user SET user_name='$user_name',GML='$GML',pw='$pw' WHERE user_id='$user_id'";
			return $sql;
		}
		function modifyBook($book_id,$book_name,$publishing_house,$author,$date){
			$sql="UPDATE book SET book_id='$book_id',book_name='$book_name',publishing_house='$publishing_house',author='$author',date='$date' WHERE book_id='$book_id'";
			return $sql;
		}
		function addUser($user_id,$user_name,$GML,$pw){
			$sql="INSERT INTO user VALUES('$user_id','$user_name','$GML','$pw')";
			return $sql;
		}
		function addBook($book_id,$book_name,$publishing_house,$author,$date){
			$sql="INSERT INTO book VALUES".
				"('$book_id','$book_name','$publishing_house','$author','$date','0')";
			return $sql;
		}
	}
	/**
	* 
	*/
	class Book
	{
		private $book_id;
		private $book_name;
		private $publishing_house;
		private $author;
		private $date;
		private $state;
		function __construct($id,$name,$ph,$a,$d,$s)
		{
			$this->book_id=$id;
			$this->book_name=$name;
			$this->publishing_house=$ph;
			$this->author=$a;
			$this->date=$d;
			$this->state=$s;
		}
		function getBookID(){
			return $this->book_id;
		}
		function getBookName(){
			return $this->book_name;
		}
		function getPublishingHouse(){
			return $this->publishing_house;
		}
		function getAuthor(){
			return $this->author;
		}
		function getDate(){
			return $this->date;
		}
		function getState(){
			return $this->state;
		}
	}

?>