class Main 
{
    private class MyClass 
    {
        // Method to print a message
        public void printMessage() 
        {
            System.out.println("Hello, World!");
        }

        // Method to get the current date as a string
        public String getCurrentDate() 
        {
            return java.time.LocalDate.now().toString();
        }
    }

    // Main method to run the program
    public static void main(String[] args) 
    {
        // Create a new instance of the class
        MyClass myObject = new MyClass();
        // Call the method to print the message
        myObject.printMessage();
        // Call the method to get the current date
        String currentDate = myObject.getCurrentDate();
        // Print the current date
        System.out.println("Current date: " + currentDate);
    }
}

