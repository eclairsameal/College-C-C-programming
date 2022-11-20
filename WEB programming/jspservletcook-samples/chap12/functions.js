<script language="JavaScript"> 

function CheckEmail(email)
{
    var firstchunk,indx,secondchunk

    if (email == ""){
        alert("Please make sure you have entered a valid email before submitting the info.")

        return false
    }

    //get the zero-based index of the "@" character
    indx = email.indexOf("@")

    //if the string does not contain an @ then then return true
    if (indx == -1 ){

        alert("Please make sure you have entered a valid email before submitting the info.")

        return false
    }

    //if the first part of email is < 2 chars and second part < 7 chars
    //(arbitrary but workable criteria) then reject the input address

    firstchunk = email.substr(0,indx) //up to but not including the "@"

    //start at char following the "@" and include up to end of email addr
    secondchunk = email.substr(indx + 1) 

    //if the part  following the "@" does not include a period "." then
    //also return false
    if ((firstchunk.length < 2 ) || (secondchunk.length < 7) ||
    (secondchunk.indexOf(".") == -1)){ 

    alert("Please make sure you have entered a valid email before submitting the info.")

    return false
}

//the email was okay; at least it had a @, more than 1 username chars,
//more than 6 chars after the "@", and the substring after the "@"
// contained a "." char

return true

}//CheckEmail

function CreateWindow(uri) {

    var newWin = window.open(uri,'newwin1','width=500,height=400,resizable,scrollable,scrollbars=yes');
    newWin.focus();

} 

</script>
