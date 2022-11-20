// Survey.java
// This servlet processes the consumer electronics survey 
//  form, updating the file that stores the survey data 
//  and producing the current total votes in the survey.
//  The survey data file, survdat.dat, is stored on the Web server.

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
public class Survey extends HttpServlet {
    public void doPost(HttpServletRequest request,
                       HttpServletResponse response)
        throws ServletException, IOException {
        int votes[] = null;
        int index;
        int vote; 
        File survdat = new File("survdat.dat");
        String gender;
        String products[] = {"Conventional TV", "HDTV", "VCR",
                           "CD Player", 
                           "Mini CD player/recorder",
                           "DVD player", "Other"};

// Set the content type for the response output and get a writer

        response.setContentType( "text/html" ); 
        PrintWriter servletOut = response.getWriter();

// Produce the head of the output document

        servletOut.println("<html><head>");
        servletOut.println(
                 "<title> Return message </title></head><body>");

// If the file already exists, read in its data

        if (survdat.exists()) {
            ObjectInputStream indat = new ObjectInputStream(
                            new FileInputStream(survdat));
            votes = (int []) indat.readObject();
            indat.close(); 
        }

// If the file does not exist (this is the first vote), create the 
//  votes array

        else
            votes = new int[14];

// Get the gender of the survey respondee

        gender = request.getParameter("gender");

// Add the consumer electronics vote of the response to the
//  votes array

        vote = Integer.parseInt(request.getParameter("vote"));
        if (gender.equals("male")) vote += 7;
        votes[vote]++;

// Write updated votes array to disk

        ObjectOutputStream outdat = new ObjectOutputStream(
            new FileOutputStream(survdat));
        outdat.writeObject(votes);
        outdat.flush();
        outdat.close();

// Create the initial response information
 
        servletOut.println("<h3>Thank you for participating in the");
        servletOut.println(" Consumer Electronics Survey</h3>");
        servletOut.println("<h4>Current Survey Results:</h4>");

// Create the total votes return information for female respondents
      
        servletOut.println("<h5>For Female Respondents </h5>");
        for (index = 0; index < 7; index++) {
            servletOut.print(products[index]);
            servletOut.print(": ");
            servletOut.println(votes[index]);
            servletOut.println("<br />");
        }

 // Create the total votes return information for male respondents
      
        servletOut.println("<h5>For Male Respondents </h5>");
        for (index = 7; index < 14; index++) {
            servletOut.print(products[index - 7]);
            servletOut.print(": ");
            servletOut.println(votes[index]);
            servletOut.println("<br />");
        }     
        servletOut.close();
    }
  }
