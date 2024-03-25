#include "Product.h"
#include "Store.h"


int main() {
	Store lidl_slatina(250);
	Store kaufland_druzhba(300);

	Product kebabche("kebabche", "sami-m", 0.99, 1);
	lidl_slatina.addProduct(kebabche);

	kaufland_druzhba.addProduct(kebabche);
	kaufland_druzhba.addProduct("lutenica", "deroni", 4.19, 5);

	Store kaufland_lyulin(kaufland_druzhba);
	kaufland_lyulin.addProduct("kyufte", "tandem", 0.98, 2);

	std::cout << "Kaufland Druzhba ";
	kaufland_druzhba.printAvailableProducts();
	std::cout << "\n";

	std::cout << "Lidl Slatina ";
	lidl_slatina.printAvailableProducts();
	std::cout << "\n";

	std::cout << "Kaufland Lylin ";
	kaufland_lyulin.printAvailableProducts();
	std::cout << "\n";

	return 0;
}