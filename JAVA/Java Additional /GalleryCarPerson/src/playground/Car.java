package playground;

public class Car {
	private String plate;
	private Person owner;

	public Car(String plate,Person owner) {
		
		this.plate = plate;
		this.owner=owner;
	}
	
	
	public Person getOwner() {
		return owner;
	}


	public void setOwner(Person owner) {
		this.owner = owner;
	}
	public String getPlate() {
		return plate;
	}
	

	public void setPlate(String plate) {
		this.plate = plate;
	}


	
	
	public void introduceYourself() {
		String intro="\n";
		intro="Selam ben "+ getPlate()+" plakali araba,";
		if(owner!=null) {
			intro+=" my owner is "+owner.getName();
		}
		System.out.println(intro);
		
	}
	
}
