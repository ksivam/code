import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by Aarthi on 8/18/15.
 * Implement an animal shelter check out
 * process using queue data structure.
 */
public class AnimalShelter {

    private Queue<Dog> dogs = new LinkedList<Dog>();
    private Queue<Cat> cats = new LinkedList<Cat>();
    private Queue<Animal> all = new LinkedList<Animal>();

    public AnimalShelter() {
    }

    public void qAny(Animal animal) {
        animal.isAvaiable = true;

        all.add(animal);
        if(animal instanceof Dog){
            dogs.add((Dog)animal);
        } else {
            cats.add((Cat)animal);
        }
    }

    public void qCat(Cat cat){
        this.qAny(cat);
    }

    public void qDog(Dog dog){
        this.qAny(dog);
    }

    public Dog dDog(){
        Dog dog = dogs.poll();

        if(dog != null){
            dog.isAvaiable = false;
        }

        return dog;
    }

    public Cat dCat() {
        Cat cat = cats.poll();

        if(cat != null){
            cat.isAvaiable = false;
        }

        return cat;
    }

    public Animal dAny() {
        Animal animal;

        do {
            animal = all.poll();
        } while (animal != null && !animal.isAvaiable);

        if(animal instanceof Dog){
            dogs.poll();
        } else if(animal instanceof Cat) {
            cats.poll();
        }

        return animal;
    }

    public abstract class Animal{
        public String name;
        public Boolean isAvaiable;

        public Animal(String name){
            this.name = name;
            this.isAvaiable = true;
        }
    }

    public class Cat extends Animal{

        public Cat(String name) {
            super(name);
        }
    }

    public class Dog extends Animal {

        public Dog(String name) {
            super(name);
        }
    }
}

