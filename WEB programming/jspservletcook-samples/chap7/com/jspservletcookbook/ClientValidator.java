package com.jspservletcookbook;

public class ClientValidator implements java.io.Serializable{

String email;
String password;
boolean valid;

public ClientValidator(){

    this.valid=false;}

public boolean isValid(){

	/* Use a Data Access Object to validate the email and password.
        If the validation does not fail then set this.valid to true*/
   this.valid=true;
   return valid;
   
   }

public void setEmail(String _email){

     if(_email != null && _email.length() > 0)
        email = _email;
    else
         email = "Unknown";
}

public String getEmail(){

    return email; }

public void setPassword(String _password){

     if(_password != null && _password.length() > 0)
        password = _password;
    else
         password = "Unknown"; 
}

public String getPassword(){

    return password; }

}