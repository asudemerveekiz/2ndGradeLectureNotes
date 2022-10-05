package playground;

public class Gallery {
	private String galleryName;
	private int count;
	private Car[] cars;
	private Person galleryOwner;
	
	
	public Gallery(String galleryName, Person galleryOwner) {
		this.galleryName = galleryName;
		this.galleryOwner = galleryOwner;
		count=0;
		cars=new Car[30];
	}
	
	public String getGalleryName() {
		return galleryName;
	}

	public void setGalleryName(String galleryName) {
		this.galleryName = galleryName;
	}

	public boolean addCar(Car car) {
		if(!searchCar(car)&& count<cars.length) {
			cars[count]=car;
			count++;
			return true;
		}
		return false;
	}
	
	public boolean searchCar(Car aCar) {
		for(Car item:cars) {
			if(item==aCar) {
				return true;
			}
		}
		return false;	
	}
	
	public Car searchCar(String plate) {
		for(Car item:cars) {
			if(item.getPlate()==plate) {
				return item;
			}
		}
		return null;	
	}
	
	
	public Car removeCar(String plate) {
		for(int i=0;i<count;i++) {
			if(cars[i].getPlate().compareTo(plate)==0) {
				Car theCar=cars[i];
			
				for(int j=i;j<count;j++) {
					cars[j]=cars[j+1];
				}
					cars[count-1]=null;
					count--;
					return theCar;
				}
		}
			return null;
			
	
	}
		
	public boolean sellCar(String plate,Person newOwner) {
		Car soldCar=removeCar(plate);
		if(soldCar!=null) {
			soldCar.setOwner(newOwner);
			return true;
		}
		return false;	
		
	}
	
	public int getCount() {
		return count;
	}

	public void setCount(int count) {
		this.count = count;
	}

	public Car[] getCars() {
		return cars;
	}

	public void setCars(Car[] cars) {
		this.cars = cars;
	}

	public Person getGalleryOwner() {
		return galleryOwner;
	}

	public void setGalleryOwner(Person galleryOwner) {
		this.galleryOwner = galleryOwner;
	}

	public void introduceYourself() {
		String intro = "This is a car gallery named "+ galleryName; intro += ", owned by " + galleryOwner.getName();
		intro += ". There are currently " + count + " cars to sell.";
		System.out.println(intro);
	}
}
