import java.util.Scanner;

public class StudentGradeCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("STUDENT GRADE CALCULATOR");
        System.out.println("-----------------------");
        
        // Input number of subjects
        System.out.print("Enter the number of subjects: ");
        int numSubjects = scanner.nextInt();
        
        // Input marks for each subject
        int[] marks = new int[numSubjects];
        int totalMarks = 0;
        
        for (int i = 0; i < numSubjects; i++) {
            System.out.printf("Enter marks for subject %d (out of 100): ", i + 1);
            marks[i] = scanner.nextInt();
            
            // Validate input
            while (marks[i] < 0 || marks[i] > 100) {
                System.out.println("Invalid marks! Please enter marks between 0 and 100.");
                System.out.printf("Enter marks for subject %d (out of 100): ", i + 1);
                marks[i] = scanner.nextInt();
            }
            
            totalMarks += marks[i];
        }
        
        // Calculate average percentage
        double averagePercentage = (double) totalMarks / numSubjects;
        
        // Determine grade
        String grade;
        if (averagePercentage >= 90) {
            grade = "A+";
        } else if (averagePercentage >= 80) {
            grade = "A";
        } else if (averagePercentage >= 70) {
            grade = "B";
        } else if (averagePercentage >= 60) {
            grade = "C";
        } else if (averagePercentage >= 50) {
            grade = "D";
        } else {
            grade = "F";
        }
        
        // Display results
        System.out.println("\nRESULTS");
        System.out.println("-------");
        System.out.println("Total Marks: " + totalMarks);
        System.out.printf("Average Percentage: %.2f%%\n", averagePercentage);
        System.out.println("Grade: " + grade);
        
        scanner.close();
    }
}