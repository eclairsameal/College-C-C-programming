package com.jspservletcookbook;

import javax.servlet.*;
import javax.servlet.http.*;

public class Controller extends HttpServlet {
       
    public void doGet(HttpServletRequest request, 
        HttpServletResponse response) 
         throws ServletException, java.io.IOException {

        RequestDispatcher dispatcher = null;
        String param = request.getParameter("go");
             if (param == null)
                 throw new 
                     ServletException("Missing parameter in Controller.");
             else if (param.equals("weather"))
                 dispatcher = getServletContext().
                     getNamedDispatcher("Weather");
             else if (param.equals("maps"))
                 dispatcher = getServletContext().
                     getNamedDispatcher("Maps");
            else
                throw new ServletException(
                    "Improper parameter passed to Controller.");
         /*check for a null dispatcher, then 
            dispatch the request to the correct URL*/
        if (dispatcher != null)
            dispatcher.forward(request,response);
        else
            throw new ServletException(
              "Controller received a null dispatcher.");
    }
}

