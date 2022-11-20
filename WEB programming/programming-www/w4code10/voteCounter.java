// voteCounter.java
// This servlet processes the ballot form, returning a 
//  page asking for a new vote if no vote was made on the
//  ballot. For legitimate ballots, the vote is added to
//  the current totals and those totals are presented to
//  the user in a return page.
//  A cookie is returned to the voter, recording the fact
//  that a vote was received. The servlet examines all votes
//  for cookies to ensure there is no mulitple voting
//  The voting data file, votesdat.dat, is stored on the Web server.

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;

public class voteCounter extends HttpServlet {

    public void doPost(HttpServletRequest request,
                       HttpServletResponse response)
        throws ServletException, IOException {
        Cookie cookies[] = null;
        Cookie newCookie;
        int votes[] = null;
        int index;
        String vote;
        File votesdat = new File("C:/jswdk-1.0.1/src/votesdat.dat");
        String candidates[] = {"Daren Dogman", "Timmy Taildragger", 
                               "Don Dogpile"};

// Set content type for response and get a writer

        response.setContentType("text/html"); 
        PrintWriter servletOut = response.getWriter();

// Write the response document head

        servletOut.println("<html><head>");
        servletOut.println("<title> Return message - </title></head><body>");

// Get cookies from the request

        cookies = request.getCookies();

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

        else {
            votes = new int[3];
        }


// Check to see if there was a vote on the form

        vote = request.getParameter("vote");
        if (vote == null) {  // There was no vote

// Create the return page

            servletOut.println(
                "You submitted a ballot with no vote marked <br />");
            servletOut.println(
                "Please mark the ballot and resubmit");
        }  // end of if votes.equals("") ...

        else {  // There was a vote
                 
// Check the cookies to see if this voter voted before

            if (cookies == null || cookies.length == 0){  

// Add the new vote of the response to the
//  votes array

                if (vote.equals("Dogman")) 
                    votes[0]++;
                else if (vote.equals("Taildragger"))
                    votes[1]++;
                else votes[2]++;

// Write updated votes array to disk

                ObjectOutputStream outdat = new ObjectOutputStream(
                                        new FileOutputStream(votesdat));
                outdat.writeObject(votes);
                outdat.flush();
                outdat.close();

// Attach a cookie to the response

                newCookie = new Cookie("iVoted", "true");
                newCookie.setMaxAge(5);
                response.addCookie(newCookie);

// Write a response message

                servletOut.println("Your vote has been received");
                servletOut.println(
                    "<br /> <br /> Current Voting Totals:<br />");

// Create the total votes return information 
      
                for (index = 0; index < 3; index++) {
                    servletOut.println("<br />");
                    servletOut.print(candidates[index]);
                    servletOut.print(": ");
                    servletOut.println(votes[index]);
                }
            }  // end of if there were no cookies
            
            else {  // There was at least one cookie

// Check the cookie to see if this user voted before

                if (cookies[0].getName().equals("iVoted") && 
                    cookies[0].getValue().equals("true")) {  
                    servletOut.println(
                  "Your vote is illegal - you have already voted!");
                }  // end of if (cookies[0] ...

            }  // end of else clause - there was a cookie

        }  // end of else (there was a vote)

// Finish response document and close the stream

         servletOut.println("</body> </html>"); 
         servletOut.close();       
    }  // end of doPost

}  // end of voteCounter

