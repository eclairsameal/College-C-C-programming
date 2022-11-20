// JDBCServlet.java
//  This servlet receives an SQL query from its HTML document,
//   connects to the cars database, performs the query on the
//   database, and returns an HTML table of the results of the
//   query

package jdbcservlet;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.util.*;
import java.sql.*;

public class JDBCServlet extends HttpServlet {
  private Connection myCon;
  private Statement myStmt;

  // The init method - instantiate the db driver, connect to the
  //  db, and create a statement for an SQL command

  public void init() {

    // Instantiate the driver for MySQL

    try {
      Class.forName("org.gjt.mm.mysql.Driver").newInstance();
    }
    catch (Exception e) {
      e.printStackTrace();
    }

    // Create the connection to the cars db

    try {
      myCon = DriverManager.getConnection (
              "jdbc:mysql://localhost/cars?user=root");
    }
    catch (SQLException e) {
      e.printStackTrace();
    }

    // Create the statement for SQL queries

    try {
      myStmt = myCon.createStatement();
    }
    catch (Exception e) {
      e.printStackTrace();
    }
  }  //** end of the init method

  // The doPost method - get the query, perform it, and produce
  //  an HTML table of the results

  public void doPost(HttpServletRequest request, 
                     HttpServletResponse response)
               throws ServletException, IOException {
    ResultSet result;
    String query, colName, dat;
    int numCols, index;
    ResultSetMetaData resultMd;

    // Get the SQL request command

    query = request.getParameter("Query");

    // Set the MIME type and get a writer

    response.setContentType("text/html");
    PrintWriter out = response.getWriter();

    // Create the initial html and display the request

    out.println("<html>");
    out.println("<head><title>JDBCServlet</title></head>");
    out.println("<body>");
    out.print("<p><b>The query is: </b>" + query + "</p>");

    // Perform the query

    try {
      result = myStmt.executeQuery(query);

    // Get the result's metadata and the number of result rows

      resultMd = result.getMetaData();
      numCols = resultMd.getColumnCount();

      // Produce the table header and caption

      out.println("<table border>");
      out.println("<caption> <b> Query Results </b> </caption>");
      out.println("<tr>");

      // Loop to produce the column headings

      for (index = 1; index <= numCols; index++) {
        colName = resultMd.getColumnLabel(index);
        out.print("<th>" + colName + "</th>");
      }

    out.println("</tr>");

    // Loop to produce the rows of the result

    while (result.next()) {
      out.println("<tr>");

      // Loop to produce the data of a row of the result

      for (index = 0; index < numCols; index++) {
        dat = result.getString(index + 1);
        out.println("<td>" + dat + "</td>");
      }  //** end of for (index = 0; ...

      out.println("</tr>");
    }  //** end of while (result.next()) ...

    out.println("</table>");

    }  //** end of try

    catch (Exception e) {
      e.printStackTrace();
    }  //** end of catch

    out.println("</body></html>");
  }  //** end of doPost method
}  //** end of class JDBCServlet

