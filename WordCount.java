
import java.util.*;
import java.io.*;

public class WordCount {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner console = new Scanner(System.in);
        System.out.print("What is the name of the text file? ");
        String fileName = console.nextLine();
        Scanner input = new Scanner(new File(fileName));

        Map<String, Integer> wordCounts = new TreeMap<String, Integer>();
        while (input.hasNext()) {
            String next = input.next().toLowerCase();
            if (!wordCounts.containsKey(next)) {
                wordCounts.put(next, 1);
            } else {
                wordCounts.put(next, wordCounts.get(next) + 1);
            }
        }

        System.out.println("Total words = " + wordCounts.size());
        System.out.print("Minimum number of occurrences for printing? ");
        int min = console.nextInt();
        for (String word : wordCounts.keySet()) {
            int count = wordCounts.get(word);
            if (count >= min)
                System.out.println(count + "\t" + word);
        }
    }
}
