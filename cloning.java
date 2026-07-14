import java.util.*;


class Book implements Cloneable {
    String title;
    String author;

    Book(String title, String author) {
        this.title = title;
        this.author = author;
    }

    @Override
    protected Book clone() throws CloneNotSupportedException {
        // default shallow copy (safe since String is immutable)
        return (Book) super.clone(); 
    }
}



class Library implements Cloneable {
    String name;
    List<Book> books;

    Library(String name) {
        this.name = name;
        this.books = new ArrayList<>();
    }

    void addBook(Book book) {
        books.add(book);
    }

    // Shallow clone → shares same books list reference
    Library shallowClone() throws CloneNotSupportedException {
        return (Library) super.clone(); 
    }

    // Deep clone → creates new list + new Book objects
    Library deepClone() throws CloneNotSupportedException {
        Library cloned = (Library) super.clone(); 

        cloned.books = new ArrayList<>(); 

        for (Book book : this.books) {
            cloned.books.add(book.clone()); 
        }

        return cloned;
    }


    void display() {
        System.out.println("Library : " + name);
        for (Book book : books) {
            System.out.println("Book : " + book.title + ", Author : " + book.author);
        }
    }
}




//Please Do not change anything below, It is only for your reference.
/*

This is the driver code that will execute and demonstrate the functionality of your class `Library` and the class 'Book'.


public class Main {

    public static void main(String[] args) {
    

        String name;
        List<String> titles, List<String> authors;

        //creating the Library class object
        Library library = new Library(name);
        
        //adding the title and author names to in the list of books present in the class Library
        for (int j = 0; j < x; j++) {
            library.addBook(new Book(titles.get(j), authors.get(j)));
        }

        System.out.println("Original Library : ");
        
        //calling the display function to display the original details that we set in above part of code
        library.display();

        //cloning objects using shallowClone and deepClone clone methods
        Library shallowLibrary = library.shallowClone();
        Library deepLibrary = library.deepClone();


        int changeIndex;
        String changeTitle, changeAuthor;

        //changing the title and author of the book present at index changeIndex using the original library object
        library.getBooks().get(changeIndex).title = changeTitle;
        library.getBooks().get(changeIndex).author = changeAuthor;


        System.out.println("\nAfter Modification : ");
        System.out.println("\nOriginal Library : ");
        
        //calling the display method through original library object to print the output
        library.display();

            
        System.out.println("\nShallow Clone : ");
            
        //calling the display method through shallow clone object to print the output    
        shallowLibrary.display();

            
        System.out.println("\nDeep Clone : ");
            
        //calling the display method through deep clone object to print the output
        deepLibrary.display();

        scanner.close();
    }
}

*/

/*
//Below are the output statements

System.out.println("Library : " + name);
System.out.println("Book : " + book.title + ", Author : " + book.author);

*/
