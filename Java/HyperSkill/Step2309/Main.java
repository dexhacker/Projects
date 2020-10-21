import java.util.Objects;

public class Main {

    public static void main(String[] args) {
        ComplexNumber a = new ComplexNumber(1, 1);
        ComplexNumber b = new ComplexNumber(1, 1);
        System.out.println(a.equals(b)); // must return true
        System.out.println(a.hashCode() == b.hashCode());  // must be equal to b.hashCode()
    }

}

class ComplexNumber {

    private final double re;
    private final double im;

    public ComplexNumber(double re, double im) {
        this.re = re;
        this.im = im;
    }

    public double getRe() {
        return re;
    }

    public double getIm() {
        return im;
    }

    @Override
    public boolean equals(Object object) {
        if (this == object) {
            return true;
        }

        if (!(object instanceof ComplexNumber)) {
            return false;
        }

        ComplexNumber complexNumber = (ComplexNumber) object;

        return this.re == complexNumber.getRe() && this.im == complexNumber.getIm();
    }

    @Override
    public int hashCode() {
        return Objects.hash(this.re, this.im);
    }
}
