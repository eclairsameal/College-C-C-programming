<%@ page 
  import = "java.sql.*"
  contentType = "text/html; charset = utf-8"
  language = "java"
%>
<html>
<head><title>Search</title></head>
<body>
<%
  Connection con = null; // 連接資料庫/
  try{
    Class.forName("com.mysql.jdbc.Driver");
    String database = "students";
    String url = "jdbc:mysql://localhost/"+database;
      con = DriverManager.getConnection(url,"root","web123");  / 此為資料庫帳密 
  }
  catch(ClassNotFoundException e) {
    out.println("Class Not Found!");
    return;
  } // 連接失敗
  Statement  statement = con.createStatement();
  String query = "select * from question";   // SQL指令
  ResultSet result = statement.executeQuery(query);   // 執行SQL指令 並存到 query
  // 列出資料
  out.println("<table border = '1'><caption><h3>Results</h3></caption>");
    ResultSetMetaData rsmd = result.getMetaData();
    int columnCount = rsmd.getColumnCount();  // 欄位數
    out.println("<tr align = 'center'>");
    for (int i = 1; i <= columnCount; i++) {
      String rname = rsmd.getColumnName(i);
      out.println("<td>" + rname + "</td>"); 
    }   // 列出所有欄位
    out.println("</tr>");
    while(result.next()) {
      String student_id = result.getString("student_id");
      String student_name = result.getString("student_name");
      int answers = result.getInt("answers");
      int corect = result.getInt("corect");
      out.println("<tr align = 'center'><td>");
      out.println(student_id + "</td><td>" + student_name + "</td><td>" + answers + "</td><td>"+ corect + "</td></tr>");  
    }  // 列出每一筆資料
  out.println("</table>");
  statement.close(); // 關閉執行對象
  con.close(); // 關閉資料庫連接  
%>
</body>
</html>