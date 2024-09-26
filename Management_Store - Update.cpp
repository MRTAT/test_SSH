
// enter: name; price; quantity

#include <iostream>

#include <string>

// menu

int menu()
{

	system("cls");
	int choice_menu;
	std::cout << "======== MENU ========\n";
	std::cout << "1. Show products.\n";
	std::cout << "2. Add new products.\n";
	std::cout << "3. Delete a products.\n";
	std::cout << "4. Exit.\n";

	std::cout << "\n======== YOUR CHOICE ========\n";
	std::cout << "Enter option 1 -> 4: ";
	std::cin >> choice_menu;
	std::cout << "============ === ============\n";

	return choice_menu;
}

struct Product
{
	std::string name;
	double price;
	int quantity;

	friend std::istream& operator>>(std::istream &is, Product &p)
	{
		std::cout << "Enter name product: ";
		is.ignore();
		getline(is, p.name);

		std::cout << "Enter price of product: ";
		is >> p.price;

		std::cout << "Enter quantity of product: ";
		is >> p.quantity;

		return is;

	}

	friend std::ostream& operator<<(std::ostream &os, Product p)
	{
		os << "Name:  " << p.name << " || Price: " << p.price << " || Quantity: " << p.quantity << "\n"; 
		return os;
	}

};

void print_out(Product *products, int size);
void addProduct(Product *&products, int &size);
void delProduct(Product *&products, int &size, Product del_product);


void print_out(Product *products, int size)
{
	if (!size)
	{
		std::cout << "\nEMPTY PRODUCT!\n";
	}
	else{
	for (int i = 0; i < size; i++)
	{
		std::cout << products[i] << "\n";  // Funct friend os will print out all data necessary
	}
	}
}

void addProduct(Product *&products, int &size)
{
	Product new_products; // create a struct, almost of input data

	std::cin >> new_products;  // is the same parameter: is new element

	// Sign struct to Array dynamic
	int new_size = size + 1;
	Product *tmp = new Product[new_size];

	// Copy 
	for(int i = 0; i < size; i ++)
	{
		tmp[i] = products[i];
	}

	// Sign new value

	tmp[new_size - 1] = new_products;  // Add more data in here

	delete[] products;  // delete memory area of pointer manage => Product *&products

	// Sign again
	
	products = tmp;
	size = new_size;
}

void delProduct(Product *&products, int &size)
{
	std::string del_element;
	std::cout << "Enter name product (DEL): ";
	std::cin >> del_element;
	
	int flagIndex = -1;  // Flag take index for name
	
	for(int i = 0; i < size; i++)
	{
		if (products[i].name == del_element)
		{
			flagIndex = i;
		}
	}

	// DELETE
	
	for(int i = flagIndex; i <  size - 1; i++)
	{
		products[i] = products[i+1];
	}

	size --;

	// using array dynamic
	Product *tmp = new Product[size];

	// Copy
	for(int i = 0; i < size; i++)
	{
		tmp[i] = products[i];
	}

	// Delete
	delete[] products;

	// Sign again
	products = tmp;


}


int main()
{

	/*
	Product p;
	std::cin >> p;
	std::cout << p;
	*/

	int size = 0;
	Product *products = new Product[size];  

	while (true)
	{
		int choice = menu();
		switch (choice)
		{
		case 1:
			std::cout << "\n=== THE LINE HAS FULL PRODUCTS ===\n\n";
			print_out(products, size);
		
			break;
		case 2:
			std::cout << "\n===     ADD A NEW PRODUCT      ===\n\n";
			addProduct(products, size);
			std::cout << "\nSuccessfully ADD!";
			break;
		case 3:
			// Delete
			std::cout << "===      DELETE A PRODUCT      ===\n\n";
			delProduct(products, size);
			std::cout << "\nSuccessfully DELETE!";
			break;
		case 4:
			std::cout << "\n----- BYE (*_*) BYE ----- \n";
			return 0;

		default:
			std::cout << "Error Input! Please, Enter again... \n";
			continue;
		}

		std::cout << "\n=== DO YOU WANT TO CONTINUE ! === : \n";
		int check_continue;
		std::cout << "Enter [1 / 0] >> ";
		std::cin >> check_continue;

		if (!check_continue)
		{
			std::cout << "\n=== THANK YOU FOR YOUR EXPERIENCE (*_*) ===";
			break;
		}

	}

}