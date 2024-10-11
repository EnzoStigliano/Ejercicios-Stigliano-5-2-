package Ejercicio1;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JTextArea;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class Ejercicio1 extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JButton Botonzo;
	private JTextArea Areaza;
	private JLabel lblNewLabel;
	private JLabel lblNewLabel_1;
	private JTextField Nombre;
	private JTextField Edad;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Ejercicio1 frame = new Ejercicio1();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public Ejercicio1() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 328);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(null);
		{
			Botonzo = new JButton("Mostrar");
			Botonzo.setBounds(335, 11, 89, 23);
			contentPane.add(Botonzo);
		}
		{
			Areaza = new JTextArea();
			Areaza.setBounds(10, 80, 414, 185);
			contentPane.add(Areaza);
		}
		{
			lblNewLabel = new JLabel("Ingrese nombre");
			lblNewLabel.setBounds(10, 15, 76, 14);
			contentPane.add(lblNewLabel);
		}
		{
			lblNewLabel_1 = new JLabel("Ingrese edad");
			lblNewLabel_1.setBounds(10, 40, 64, 14);
			contentPane.add(lblNewLabel_1);
		}
		{
			Nombre = new JTextField();
			Nombre.setBounds(106, 12, 86, 20);
			contentPane.add(Nombre);
			Nombre.setColumns(10);
		}
		{
			Edad = new JTextField();
			Edad.setBounds(106, 37, 86, 20);
			contentPane.add(Edad);
			Edad.setColumns(10);
		}
		Botonzo.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String nom = Nombre.getText();
				int edad = Integer.parseInt(Edad.getText());
				
				Areaza.append("El nombre es: " + nom + "\n");
				Areaza.append("La edad es: " + edad);
			}
		});
	}
}
