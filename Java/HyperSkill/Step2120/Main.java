public class Main {

    public static void main(String[] args) {
        Circle circle = new Circle(10);
        System.out.println(circle.getPerimeter());
        System.out.println(circle.getArea());

        Triangle triangle = new Triangle(3, 4, 5);
        System.out.println(triangle.getPerimeter());
        System.out.println(triangle.getArea());

        Rectangle rectangle = new Rectangle(5, 10);
        System.out.println(rectangle.getPerimeter());
        System.out.println(rectangle.getArea());
    }

}

abstract class Shape {

    abstract double getPerimeter();

    abstract double getArea();
}

class Triangle extends Shape {
    private double a;
    private double b;
    private double c;

    public Triangle(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public double getPerimeter() {
        return this.a + this.b + this.c;
    }

    public double getArea() {
        double s = (this.a + this.b + this.c) / 2;
        return Math.sqrt(s * (s - this.a) * (s - this.b) * (s - this.c));
    }

}

class Rectangle extends Shape {
    private double a;
    private double b;

    public Rectangle(double a, double b) {
        this.a = a;
        this.b = b;
    }

    public double getPerimeter() {
        return (this.a + this.b) * 2;
    }

    public double getArea() {
        return this.a * this.b;
    }

}

class Circle extends Shape {
    private double a;

    public Circle(double a) {
        this.a = a;
    }

    public double getPerimeter() {
        return Math.PI * this.a * 2;
    }

    public double getArea() {
        return this.a * this.a * Math.PI;
    }

}
