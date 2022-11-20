/* This is Greeting.java
   A servlet to illustrate a simple GET request
   */
import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;

public class Greeting extends HttpServlet {

    public void doGet(HttpServletRequest request,
		      HttpServletResponse response)
        throws ServletException {
        PrintWriter returnHTML;
        response.setContentType("text/html");
        returnHTML = response.getWriter();
        returnHTML.println("<html><head><title>\n");
        returnHTML.println("A simple GET servlet\n");
        returnHTML.println("</title></head><body>\n");
        returnHTML.println("<h2> Greetings, this is your servlet answering </h2>\n");
        returnHTML.println("</body></html>\n");
        returnHTML.close(); 
    }
}

