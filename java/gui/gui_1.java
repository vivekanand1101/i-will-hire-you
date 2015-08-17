import javax.swing.JOptionPane;

public class gui_1 {
    public static void main (String[] args)
    {
        String s1 = JOptionPane.showInputDialog("Enter number");
        String s2 = JOptionPane.showInputDialog("Enter the second number");

        int n1 = Integer.parseInt(s1);
        int n2 = Integer.parseInt(s2);
        int sum = n1 + n2;

        JOptionPane.showMessageDialog(null, "The sum is: " + sum, "Sum", JOptionPane.PLAIN_MESSAGE);
    }
}
