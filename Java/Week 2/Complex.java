class Complex {
	double re;
	double im;
	
	public double abs() {
		return Math.sqrt(re*re + im*im);
	}
	
	public void add(Complex other){
		this.re += other.re;
		this.im += other.im;
	}
	
	public void sub(Complex other) {
		this.re -= other.re;
		this.im -= other.im;
	}
	
	public void mul(Complex other) {
		double tempRe = this.re * other.re - this.im * other.im;
		double tempIm = this.re * other.im + this.im * other.re;
		this.re = tempRe;
		this.im = tempIm;
	}

	public void conjugate() {
		this.im *= (-1);
	}

	public void reciprocate() {
		// re /= 0 ^ im /= 0
		double temp = ((this.re*this.re) + (this.im*this.im));
		this.re = this.re/temp;
		this.im = (-1)*(this.im/temp);
	}

	public void div(Complex c) {
		double a1 = this.re;
		double b1 = this.im;
		double a2 = c.re;
		double b2 = c.im;

		this.re = (a1*a2 + b1*b2) / (a2*a2 + b2*b2);
		this.im = (a2*b1 - a1*b2) / (a2*a2 + b2*b2);

	}
}
