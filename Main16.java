// College Class
class College {
    private String name;
    private String id;

    public College(String name, String id) {
        this.name = name;
        this.id = id;
    }

    public void displayDetails() {
        System.out.println("College Name : " + name);
        System.out.println("College ID : " + id);
    }
}

// University Class
class University {
    private String name;
    private List<College> colleges;

    public University(String name) {
        this.name = name;
        this.colleges = new ArrayList<>();
    }

    // Add College
    public void addCollege(String collegeName, String collegeId) {
        colleges.add(new College(collegeName, collegeId));
    }

    // Display Details
    public void displayDetails() {
        System.out.println("University Name : " + name);
        for (College college : colleges) {
            college.displayDetails();
        }
    }
}