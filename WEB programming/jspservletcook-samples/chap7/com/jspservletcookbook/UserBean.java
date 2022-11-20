package com.jspservletcookbook;

public class UserBean implements java.io.Serializable{

String username;
String email;
String department;

public UserBean(){}

public void setUsername(String _username){

    if(_username != null && _username.length() > 0)
        username = _username;
    else
         username = "Unknown";
}

public String getUsername(){

    if(username != null)
        return username;
    else
        return "Unknown"; }

public void setEmail(String _email){

     if(_email != null && _email.length() > 0)
        email = _email;
    else
         email = "Unknown";
}

public String getEmail(){

   if(email != null)
        return email;
    else
        return "Unknown";
}

public void setDepartment(String _department){

     if(_department != null && _department.length() > 0)
        department = _department;
    else
         department = "Unknown";
}

public String getDepartment(){
    
	 if(department != null)
         return department;
    else
        return "Unknown"; 
    }

}