// voteCounter2.java
// This servlet processes the ballot form, returning a 
//  page asking for a new vote if no vote was made on the
//  ballot. For legitimate ballots, the vote is added to
//  the current totals and those totals are presented to
//  the user in a return page.
//  A cookie is returned to the voter, recording the fact
//  that a vote was received. The servlet examines all votes
//  for cookies to ensure there is no mulitple voting.
// This servlet uses session tracking, rather than cookies
//  The voting data file, votesdat.dat, is stored on the Web server.

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;

public class voteCounter2 extends HttpServlet {

    public void doPost(HttpServletRequest request,
                       HttpServletResponse response)
        throws ServletException, IOException {
        HttpSession mySession;
        int votes[] = null;
        int index;
        String vote;
        File votesdat = new File("votesdat.dat");
        String candidates[] = {"Daren Dogman", "Timmy Taildragger", 
                               "Don Dogpile"};

// If the file already exists, read in its data

        if (votesdat.exists()) {
            try {
                ObjectInputStream indat = new ObjectInputStream(
                                new FileInputStream(votesdat));
                votes = (int []) indat.readObject();
                indat.close(); 
            }  // end of try
            catch(ClassNotFoundException problem) {
               problem.printStackTrace();
            }  // end of catch
        }  // end of if (votesdat...

// If the file does not exist (this is the first vote), create the 
//  votes array

        else
            votes = new int[3];


// Check to see if there was a vote on the form

        vote = request.getParameter("vote");
        if (vote == "") {  // There was no vote

// Set the content type for the response output and get a writer

            response.setContentType("text/html"); 
            PrintWriter servletOut = response.getWriter();

// Create the return page

            servletOut.println("<html>");
            servletOut.println("<title> Return message - no vote </title>");
            servletOut.println("You submitted a ballot with no vote marked");
            servletOut.println("Please mark the ballot and resubmit");
            servletOut.println("</body> </html>");
        }  // end of if votes == "" ...

        else {  // There was a vote
                  
// Get the session object, if there is one

            mySession = request.getSession(false);

// If there was no session, the vote must be ok

            if (mySession == null) {  // No previous vote

// Add the new vote of the response to the
//  votes array

                if (vote == "Dogman") 
                    votes[0]++;
                else if (vote == "Taildragger")
                    votes[1]++;
                else votes[2]++;

// Write updated votes array to disk

                ObjectOutputStream outdat = new ObjectOutputStream(
                                        new FileOutputStream(votesdat));
                outdat.writeObject(votes);
                outdat.flush();
                outdat.close();

// Create a session object and set a value to indicate a vote

                mySession = request.getSession(true);
                mySession.putValue("iVoted", "true");
                
// Set the content type for the response output and get a writer

                response.setContentType( "text/html" ); 
                PrintWriter servletOut = response.getWriter();

// Create the response header information

                servletOut.println("<html>");
                servletOut.println("<title> Return message </title>");
                servletOut.println("Your vote has been received");
                servletOut.println(
                              "<br/> <br/> Current Voting Totals:<br/>");

// Create the total votes return information 
      
                for (index = 0; index < 3; index++) {
                    servletOut.println("<br/>");
                    servletOut.print(candidates[index]);
                    servletOut.print(": ");
                    servletOut.println(votes[index]);
                }

                servletOut.close();


            }  // end of if there was no session object
            
            else {  // There was a session object

// Check the session object to see if this user voted before
            
                String names [] = mySession.getValueNames();
                if (names[0] == "iVoted" && 
                    mySession.getValue(names[0]) == "true") {  

// Set the content type for the response output and get a writer

                    response.setContentType( "text/html" ); 
                    PrintWriter servletOut = response.getWriter();

// Create the return page for illegal votes

                    servletOut.println("<html>");
                    servletOut.println("<title> Return message </title>");
                    servletOut.println("<body>");
                    servletOut.println(
                         "Your vote is illegal - you have already votes!");
                    servletOut.println("</body> </html>");
                    servletOut.close();
                }  // end of if (

            }  // end of else clause - there was a session object

        }  // end of else (there was a vote)
                
    }  // end of doPost

}  // end of voteCounter2

