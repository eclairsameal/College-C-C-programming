public class Point {
  public Point(double ix, double iy){
	setXY(ix, iy);
  }
  public void setXY(double ix, double iy){
	this.x = ix; this.y = iy;
  }
  public double getX(){return x;}
  public double getY(){return y;}
  private double x, y;
}

