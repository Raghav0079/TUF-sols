// Book class supports cloning
class Book implements Cloneable {
    String title;
    String author; 

    // Constructor to initialize book details
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


// Library class supports shallow and deep cloning
class Library implements Cloneable {
    String name;
    List<Book> books;

    // Initialize library with empty book list
    Library(String name) {
        this.name = name;
        this.books = new ArrayList<>();
    }

    // Add a book to the library
    void addBook(Book book) {
        books.add(book);
    }

    // Shallow clone → shares same books list reference
    Library shallowClone() throws CloneNotSupportedException {
        // list reference copied, not duplicated
        return (Library) super.clone(); 
    }

    // Deep clone → creates new list + new Book objects
    Library deepClone() throws CloneNotSupportedException {
        // copy primitive + references first
        Library cloned = (Library) super.clone(); 

        cloned.books = new ArrayList<>(); // create independent list

        for (Book book : this.books) {
            cloned.books.add(book.clone()); // clone each book separately
        }

        return cloned;
    }

    // Display library details
    void display() {
        System.out.println("Library : " + name);
        for (Book book : books) {
            System.out.println("Book : " + book.title + ", Author : " + book.author);
        }
    }
}