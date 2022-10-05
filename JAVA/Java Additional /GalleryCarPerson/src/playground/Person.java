package playground;

public class Person {
	private String name;
	private Car car;
	
	
	
	public Person(String name) {
		this.name = name;
	
	}

	public String getName() {
		return name;
	}
	
	public Car getCar() {
		return car;
	}
	public void setCar(Car car) {
		this.car = car;
	}
	
	public void introduceYourself() {
		System.out.print("Selam, adım "+name);
		if(car!=null) {
			System.out.print(" arabamın plakası "+car.getPlate());
		}
	}
	


}
