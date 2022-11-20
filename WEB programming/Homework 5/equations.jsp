<%@ page import="java.util.Random"%>
<%@ page import="java.usql.*"%>
<%@ page 
import = "java.sql.*"
contentType = "text/html; charset = utf-8"
language = "java"
%>
<html>
<head><title>equations</title></head>
<body>
<%
  String student_no = request.getParameter("student_no");
  String name = request.getParameter("name");
  out.println("Student No:"+student_no+"</br>");
  out.println("Name:"+name+"</br>");
  out.println("Your question: ");
%>
<!印出訊息>
<%
  Random r = new Random();   //亂數產生題目
  int a = r.nextInt(10*2+1)-10,
      b = r.nextInt(10*2+1)-10,
      c = r.nextInt(10*2+1)-10,
      d = r.nextInt(10*2+1)-10,
      e = r.nextInt(10*2+1)-10,
      f = r.nextInt(10*2+1)-10;
  String result = "";  // 方程式一
  String result1 = "";  // 方程式二
  result = a+"x";
  if (b>=0) {result+="+"+b+"y=";}
  else{result+=b+"y=";}
  result+=c;
  out.println(result);  // 印出方程式一
  out.println(",  ");
  result1 = d+"x";
  if (e>=0) {result1+="+"+e+"y=";}
  else{result1+=e+"y=";}
  result1+=f;
  out.println(result1);  // 印出方程式二
  session.setAttribute("student_no", student_no);
  session.setAttribute("name", name); 
  session.setAttribute("a", a);
  session.setAttribute("b", b);
  session.setAttribute("c", c);
  session.setAttribute("d", d);
  session.setAttribute("e", e);
  session.setAttribute("f", f);  
  // 送出表單
  out.println("<form action = \"result.jsp\" method = \"post\">");
    out.println(" x =  "+"<input type=\"text\" name = \"ans_x\">"); 
    out.println(" y =  "+"<input type=\"text\" name = \"ans_y\">");
    out.println("<input type =\"radio\"  name =\"ans\"  value =\"No_solution\"/>"+"No solution");
    out.println("<input type =\"radio\"  name =\"ans\"  value =\"Infinite_solutions \"/>"+"Infinite solutions");
    out.println("</br>"+"<input type = \"submit\"  value = \"Submit\">");
  out.println("</form>");
%>
</body>
</html>


