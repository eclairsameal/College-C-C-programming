<%@ page import="java.usql.*"%>
<%@ page 
  import = "java.sql.*"
  contentType = "text/html; charset = utf-8"
  language = "java"
%>
<html>
<head><title> result </title></head>
<body>
  <%  
    Connection con = null; // 連接資料庫
    try{
      Class.forName("com.mysql.jdbc.Driver");
      String database = "students";
      String url = "jdbc:mysql://localhost/"+database;
       con = DriverManager.getConnection(url,"root","web123"); // 此為資料庫帳密 
    }
    catch(ClassNotFoundException e) {
      out.println("Class Not Found!");
      return;
    }  // 連接資料庫錯誤
  
  String student_no = (String) session.getAttribute("student_no");
  String name = (String) session.getAttribute("name");
  double ta = Double.parseDouble(session.getAttribute("a").toString()),
         tb = Double.parseDouble(session.getAttribute("b").toString()),
         tc = Double.parseDouble(session.getAttribute("c").toString()),
         td = Double.parseDouble(session.getAttribute("d").toString()),
         te = Double.parseDouble(session.getAttribute("e").toString()),
         tf = Double.parseDouble(session.getAttribute("f").toString());
  int a = (int)ta, b = (int)tb, c = (int)tc, d = (int)td,e = (int)te, f = (int)tf;
    // 抓的方程式的值
  out.println("</br>");  
  int f_sol = 0;
  int x=0, y=0;
  String results2 = "";
  if ((a*e-b*d)!=0) {
    x = (c*e-b*f)/(a*e-b*d);
    y = (a*f-c*d)/(a*e-b*d);
    results2 = "x = "+x+",  y = "+y+"</br>";
    f_sol = 1;
  } // 解出方程式的值
  else{
    float m1 = 0, m2 = 0, m3 = 0;
    m1 = a/d;
    m2 = b/e;
    m3 = c/f;
    if(m1==m2&&m2==m3){f_sol = 2;} // 無限多組解
    else{f_sol = 3;} // 無解
  }
    // 取的學生答案 
  String ans_x = request.getParameter("ans_x");
  String ans_y = request.getParameter("ans_y");
  String ans_radio = request.getParameter("ans");
  int ans_correctly = 0;
   // 判斷對錯
  if (!ans_x.equalsIgnoreCase("") && !ans_y.equalsIgnoreCase("")){  // 有輸入x, y
    if(f_sol==1){  // 有解 
      int t_ans_x = Integer.parseInt(ans_x);
      int t_ans_y = Integer.parseInt(ans_y);
      if(t_ans_x==x && t_ans_y==y){ans_correctly = 1;}     
    }
  }
  else{
    if(ans_radio == "No_solution"){
      if(f_sol==3){ans_correctly = 1;}     
    }
    else{ // ans_radio == "Infinite solutions"
      if(f_sol==2){ans_correctly = 1;}
    }
  }
  Statement statement = con.createStatement();
  String query = "";
  query = "SELECT * FROM question WHERE student_id='"+student_no+"'"; // 查詢指令
  ResultSet result = statement.executeQuery(query); // 結果
  int row_not = 0; // 結果數
  try{
    result.next();
    result.getString("student_name");
  }
  catch(SQLException e1) {row_not=1;} // try-catch 如果查無此資料丟出錯誤
  if (row_not==1){  // 查無此人(新增)
    if (ans_correctly==1) { // 新增一筆學生(答案正確)
      out.println("Correct, 3 seconds after the jump back home"+"</br>");
      query = "insert into question values ('" + student_no + "', '" + name + "', '" + 1 + "', '" + ans_correctly + "')";   
    }
    else{  // 新增一筆學生(答案錯誤)
      out.println("Error, 3 seconds after the jump back home"+"</br>"); 
      query = "insert into question values ('" + student_no + "', '" + name + "', '" + 1 + "', '" + ans_correctly + "')"; 
    }   
  if(statement.executeUpdate(query)>0){
    out.println("The data is inserted.");
    response.setHeader("Refresh" , "3;url=index.html"); // 3秒後跳回主頁(index.html)
  } else out.println("The data is not inserted."); // 新增失敗

  }
  else{  // 資料庫已有此學生
    query = "SELECT * FROM question WHERE student_id='"+student_no+"'"; // 查詢指令
    result = statement.executeQuery(query); // 結果
    result.next();
    int answers = result.getInt("answers"); 
    int corect = result.getInt("corect");
    answers++;
    if (ans_correctly==1) {  // 修改(答案正確)
      corect++;
      out.println("Correct, 3 seconds after the jump back home"+"</br>");
      query = "update question set answers = '"+answers+"'where student_id="+student_no;
      statement.executeUpdate(query); 
      query = "update question set corect = '"+corect+"'where student_id="+student_no;
      statement.executeUpdate(query); 
    }
    else{ // 修改(答案錯誤)
      out.println("Error, 3 seconds after the jump back home"+"</br>");
      query = "update question set answers = '"+answers+"'where student_id="+student_no;
      statement.executeUpdate(query); 
    } 
    response.setHeader("Refresh" , "3;url=index.html"); // 3秒後跳回主頁(index.html)
  }
  statement.close(); // 關閉執行對象
  con.close(); // 關閉資料庫連接
%>  

</body>
</html>
