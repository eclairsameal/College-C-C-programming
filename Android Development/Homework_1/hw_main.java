import java.util.Scanner;

public class hw_main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
	  Scanner sca = new Scanner(System.in);
	  double x1, x2, x3, x4, y1, y2, y3, y4;
		  
	  System.out.print("Enter 4 points:");
	  x1 = sca.nextDouble();
	  y1 = sca.nextDouble();
	  Point p1 = new Point(x1, y1);
	  x2 = sca.nextDouble();	  
	  y2 = sca.nextDouble();
	  Point p2 = new Point(x2, y2);
	  x3 = sca.nextDouble();	  
	  y3 = sca.nextDouble();
	  Point p3 = new Point(x3, y3);
	  x4 = sca.nextDouble();	  
	  y4 = sca.nextDouble();
	  Point p4 = new Point(x4, y4);
	  Convex c = new Convex(p1, p2, p3, p4);
	  if ((c.convex_area()) > 0)
		c.printconvex_point();
	  else System.out.println("The convex cannot be formed.");
	}

}
