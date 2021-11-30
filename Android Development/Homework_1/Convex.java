
public class Convex {
	
  Convex(Point ip1, Point ip2, Point ip3, Point ip4){
	setConvex(ip1, ip2, ip3, ip4);  
  }
  public void setConvex(Point ip1, Point ip2, Point ip3, Point ip4){
	  p1 = ip1; p2 = ip2; p3 = ip3; p4 = ip4;
  }
  public Point getPoint1(){return p1;}
  public Point getPoint2(){return p2;}
  public Point getPoint3(){return p3;}
  public Point getPoint4(){return p4;}
  public double dist (Point a, Point b) {
	return Math.sqrt((a.getX() - b.getX())*(a.getX() - b.getX()) + (a.getY() - b.getY())*(a.getY() - b.getY()));
  }
  public double triangle_area(Point pa, Point pb, Point pc) {
	  double ab_dist = dist(pa, pb), bc_dist = dist(pb, pc), ca_dist = dist(pc, pa);
	if (ab_dist + bc_dist > ca_dist && bc_dist + ca_dist > ab_dist && ca_dist + ab_dist > bc_dist) {
	  double s = (ab_dist + bc_dist + ca_dist)/2;
	  return Math.sqrt(s * (s - ab_dist) * (s - bc_dist) * (s - ca_dist));
	} else return 0; 
  }
  public double convex_area() {
	double area1 = triangle_area(getPoint1(), getPoint2(), getPoint3()), area2 = triangle_area(getPoint1(), getPoint3(), getPoint4());
	double area3 = triangle_area(getPoint1(), getPoint2(), getPoint4()), area4 = triangle_area(getPoint2(), getPoint3(), getPoint4());
	if (area1 > 0 && area2 > 0 && area3 > 0 && area4 > 0) {
	  return area1 + area2;
	} else return 0;
  }
  public void printconvex_point(){  
	System.out.print("The convex area formed by ("+getPoint1().getX()+", "+getPoint1().getY()+") "+
	"("+getPoint2().getX()+", "+getPoint2().getY()+") "+
	"("+getPoint3().getX()+", "+getPoint3().getY()+") "+
	"("+getPoint4().getX()+", "+getPoint4().getY()+") "+"is "+this.convex_area()+".");
  }
  private Point p1, p2, p3, p4;
}
