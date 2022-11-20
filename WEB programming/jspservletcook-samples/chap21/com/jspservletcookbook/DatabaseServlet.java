package com.jspservletcookbook;           

import java.sql.*;

import javax.servlet.*;
import javax.servlet.http.*;

public class DatabaseServlet extends HttpServlet {

  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
        String sql = "select * from athlete";
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;
        ResultSetMetaData rsm = null;
        
        response.setContentType("text/html");
        java.io.PrintWriter out = response.getWriter();
        out.println("<html><head><title>Typical Database Access</title></head><body>");
        out.println("<h2>Database info</h2>");
        out.println("<table border='1'><tr>");
       
        try{
            
			//load the database driver
			Class.forName ("oracle.jdbc.driver.OracleDriver");

			//The JDBC URL for this Oracle database
            String url = "jdbc:oracle:thin:@192.168.0.2:1521:ORCL";
			
			//Create the java.sql.Connection to the database
            conn = DriverManager.getConnection(url,"scott", "tiger");
		   
		   //Create a statement for executing some SQL
           stmt = conn.createStatement();
      
            rs = stmt.executeQuery(sql);
			
            rsm = rs.getMetaData();
			
            int colCount =  rsm.getColumnCount();
            
            //print column names
            for (int i = 1; i <=colCount; ++i){
                
                out.println("<th>" + rsm.getColumnName(i) + "</th>");
            }
            
            out.println("</tr>");
          
            while( rs.next()){
                
                 out.println("<tr>");
                
                for (int i = 1;  i <=colCount; ++i)
                    out.println("<td>" + rs.getString(i) + "</td>");
                
                 out.println("</tr>");
				 
                }
				
        } catch (Exception e){
            
            throw new ServletException(e.getMessage());
			
        } finally {
            
            try{
                
                stmt.close();
                conn.close();
				
            } catch (SQLException sqle){ }
            
            
        }
      
        out.println("</table><br><br>");

        out.println("</body>");
        out.println("</html>");
    
        out.close();
      
     } //doGet

}
