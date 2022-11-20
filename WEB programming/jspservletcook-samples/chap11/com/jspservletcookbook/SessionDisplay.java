package com.jspservletcookbook;           

import javax.servlet.*;
import javax.servlet.http.*;

import java.util.Date;
import java.text.DateFormat;
import java.util.Enumeration;

public class SessionDisplay extends HttpServlet {
  
 public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
        
        response.setContentType("text/html");
        java.io.PrintWriter out = response.getWriter();
        HttpSession session = request.getSession();
        Date creationTime = new Date(session.getCreationTime() );
        Date lastAccessed = new Date(session.getLastAccessedTime());
        Date now = new Date();
        DateFormat formatter = DateFormat.getDateTimeInstance(DateFormat.MEDIUM,DateFormat.MEDIUM);
        
        out.println("<html>");
        out.println("<head>");
        out.println("<title>Displaying the Session Creation and Last-Accessed Time</title>");
        out.println("</head>");
        out.println("<body>");
        out.println("<h2>Session Creation and Last-Accessed Time</h2>");
        out.println("The time and date now is: " + formatter.format(now) + "<br><br>");
        out.println("The session creation time: HttpSession.getCreationTime( ): " + formatter.format(creationTime) + "<br><br>");
        out.println("The last time the session was accessed: HttpSession.getLastAccessedTime( ): " + formatter.format(lastAccessed) );
        out.println("</body>");
        out.println("</html>");
        
        
    }
}
