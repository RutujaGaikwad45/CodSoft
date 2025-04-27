import java.util.Scanner;

/**
 * Complete ATM Banking System
 * Includes bank account management with deposit, withdrawal, and balance checking
 */
public class ATMSystem {
    
    // Bank account class
    static class BankAccount {
        private double balance;
        
        public BankAccount(double initialBalance) {
            this.balance = initialBalance;
        }
        
        public double getBalance() {
            return balance;
        }
        
        public void deposit(double amount) {
            if (amount > 0) {
                balance += amount;
                System.out.printf("Deposited $%.2f successfully.%n", amount);
            } else {
                System.out.println("Invalid deposit amount.");
            }
        }
        
        public boolean withdraw(double amount) {
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                System.out.printf("Withdrew $%.2f successfully.%n", amount);
                return true;
            }
            System.out.println("Withdrawal failed. Check amount or balance.");
            return false;
        }
    }

    // ATM interface class
    static class ATM {
        private final BankAccount account;
        private final Scanner scanner;
        
        public ATM(BankAccount account) {
            this.account = account;
            this.scanner = new Scanner(System.in);
        }
        
        public void start() {
            System.out.println("\nWelcome to JavaBank ATM");
            System.out.println("-----------------------");
            
            boolean running = true;
            while (running) {
                displayMenu();
                int choice = getChoice();
                
                switch (choice) {
                    case 1:
                        checkBalance();
                        break;
                    case 2:
                        processDeposit();
                        break;
                    case 3:
                        processWithdrawal();
                        break;
                    case 4:
                        running = false;
                        break;
                    default:
                        System.out.println("Invalid option. Try again.");
                }
            }
            
            shutdown();
        }
        
        private void displayMenu() {
            System.out.println("\nMain Menu:");
            System.out.println("1. Check Balance");
            System.out.println("2. Make Deposit");
            System.out.println("3. Withdraw Cash");
            System.out.println("4. Exit");
            System.out.print("Enter your choice (1-4): ");
        }
        
        private int getChoice() {
            while (!scanner.hasNextInt()) {
                System.out.println("Please enter a number 1-4.");
                scanner.next(); // Clear invalid input
                displayMenu();
            }
            return scanner.nextInt();
        }
        
        private void checkBalance() {
            System.out.printf("Current Balance: $%.2f%n", account.getBalance());
        }
        
        private void processDeposit() {
            System.out.print("Enter deposit amount: $");
            double amount = getAmount();
            account.deposit(amount);
        }
        
        private void processWithdrawal() {
            System.out.print("Enter withdrawal amount: $");
            double amount = getAmount();
            account.withdraw(amount);
        }
        
        private double getAmount() {
            while (!scanner.hasNextDouble()) {
                System.out.println("Please enter a valid amount.");
                scanner.next(); // Clear invalid input
                System.out.print("Enter amount: $");
            }
            return scanner.nextDouble();
        }
        
        private void shutdown() {
            scanner.close();
            System.out.println("\nThank you for using JavaBank ATM.");
            System.out.println("Please take your card. Goodbye!");
        }
    }

    // Main program
    public static void main(String[] args) {
        // Initialize bank account with $1000 balance
        BankAccount userAccount = new BankAccount(1000.00);
        
        // Create and start ATM
        ATM atm = new ATM(userAccount);
        atm.start();
    }
}