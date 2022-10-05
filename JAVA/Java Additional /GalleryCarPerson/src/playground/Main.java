package playground;

public class Main {

	public static void main(String[] args) {
		//System.out.println();
		Person person1=new Person("Asude");
		Person person2=new Person("Merve");
		Gallery gallery1=new Gallery("Cars 4 You",person1);
		Car car1=new Car("34 ABC 34", person1);
		Car car2=new Car("34 DFE 34", person2);
		person2.setCar(car2);		
		System.out.println(car1.getOwner().getName());
		person1.setCar(car1);
		System.out.println(person1.getCar().getPlate());
		System.out.println(gallery1.getGalleryOwner().getName());
		System.out.println(gallery1.getCount());
		if(gallery1.addCar(car1)) {
			System.out.println("Adding operation is successfull");
		}
		else {
			System.out.println("Adding operation is not successfull");
		}
		if(gallery1.searchCar(car1)) {
			System.out.println("Searching operation is successfull, find it.");
		}
		else {
			System.out.println("Searching operation is not successfull,couldn,'t find it.");
		}
		//satilacak arac
		gallery1.removeCar(car1.getPlate()).introduceYourself();
		if(gallery1.searchCar(car1)) {
			System.out.println("Searching operation is successfull, find it.");
		}
		else {
			System.out.println("Searching operation is not successfull,couldn,'t find it.");
		}
	
		
		
		
		
		

	}

}
