import java.util.Scanner;
import java.util.Random;

public class NumberGuessingGame {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();
        
        System.out.println("Welcome to the Number Guessing Game!");
        System.out.println("I'm thinking of a number between 1 and 100.");
        
        int totalRounds = 0;
        int totalWins = 0;
        int totalAttempts = 0;
        boolean playAgain = true;
        
        while (playAgain) {
            // Game setup
            int secretNumber = random.nextInt(100) + 1;
            int attemptsLimit = 10;
            int attemptsUsed = 0;
            boolean roundWon = false;
            
            totalRounds++;
            System.out.printf("\n--- Round %d ---\n", totalRounds);
            System.out.printf("You have %d attempts to guess the number.\n", attemptsLimit);
            
            // Guessing loop
            while (attemptsUsed < attemptsLimit && !roundWon) {
                System.out.print("\nEnter your guess (1-100): ");
                int guess;
                
                try {
                    guess = scanner.nextInt();
                    
                    if (guess < 1 || guess > 100) {
                        System.out.println("Please enter a number between 1 and 100.");
                        continue;
                    }
                    
                    attemptsUsed++;
                    
                    if (guess == secretNumber) {
                        roundWon = true;
                        totalWins++;
                        totalAttempts += attemptsUsed;
                        System.out.printf("Congratulations! You guessed the number in %d attempts!\n", attemptsUsed);
                    } else if (guess < secretNumber) {
                        System.out.println("Too low! Try again.");
                    } else {
                        System.out.println("Too high! Try again.");
                    }
                    
                    System.out.printf("Attempts remaining: %d\n", attemptsLimit - attemptsUsed);
                } catch (Exception e) {
                    System.out.println("Please enter a valid number.");
                    scanner.next(); // Clear the invalid input
                }
            }
            
            if (!roundWon) {
                System.out.printf("\nSorry, you've used all your attempts. The number was %d.\n", secretNumber);
            }
            
            // Ask to play again
            System.out.print("\nWould you like to play again? (yes/no): ");
            String playAgainInput = scanner.next().toLowerCase();
            
            if (!playAgainInput.equals("yes")) {
                playAgain = false;
            }
        }
        
        // Display final statistics
        System.out.println("\nGame Over!");
        System.out.printf("Rounds played: %d\n", totalRounds);
        System.out.printf("Rounds won: %d\n", totalWins);
        
        if (totalWins > 0) {
            double averageAttempts = (double) totalAttempts / totalWins;
            System.out.printf("Average attempts per win: %.1f\n", averageAttempts);
        }
        
        scanner.close();
    }
}