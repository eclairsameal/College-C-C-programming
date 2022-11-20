import org.apache.log4j.Logger;
import org.apache.log4j.PropertyConfigurator;

import javax.servlet.*;
import javax.servlet.http.*;

public class LoggerSkel extends HttpServlet {

  private Logger log;

  public void init(){
  
  PropertyConfigurator.configure(getServletContext().getRealPath("/") +
     "WEB-INF/classes/servletLog.properties");
  log = Logger.getLogger(LoggerSkel.class);
  log.debug("Instance created of: " + getClass().getName());
  
  }

  public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, java.io.IOException {
    
    //do logging here if necessary
      
    } //end doGet
   
}
