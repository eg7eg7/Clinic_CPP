// IceCreamShop.cpp : Defines the entry point for the console application.
//
#pragma warning(disable: 4996)
#include "stdafx.h"
#include <iostream>
#include "iceCreamShop.h"
#include "Customer.h"
#include "Smoothie.h"
#include "Milkshake.h"
#include "IceCreamWithBelgianWaffle.h"
#include "CrepeWithIceCream.h"
#include "Order.h"
using namespace std;

void initMenu(Menu& menu)
{
	BelgianWaffle& waffle = BelgianWaffle(Dessert(MenuItem(eItemId(BELGIAN_WAFFLE), "The belgians are not that innocent", 40, "milk, olive oil, flour"), eDessertSize(SMALL_DESSERT)), eSyrup(MAPLE_SYRUP));
	IceCreamBall& iceCream = IceCreamBall(Dessert(MenuItem(eItemId(ICE_CREAM), "Fresh italian ice cream", 10, "milk"), eDessertSize(SMALL_DESSERT)), eTaste(VANILLA_DTASTE));
	Crepe& crepe = Crepe(Dessert(MenuItem(eItemId(CREPE), "Original french cuisine", 30, "milk, olive oil, flour"), eDessertSize(LARGE_DESSERT)), eSpread(NUTELLA_SPREAD_WITH_COCOS));
	Smoothie& smoothie = Smoothie(Drink(MenuItem(eItemId(SMOOTHIE), "Enjoy a refreshing drink like at the beach", 25, "100% Mango"), eDessertSize(LARGE_DESSERT)), Fruit(eFruit(MANGO)));
	Milkshake& milkshake = Milkshake(Drink(MenuItem(eItemId(MILKSHAKE), "Take it, you deserve it", 35, "100% Mango"), eDessertSize(LARGE_DESSERT)), eDrinkTaste(COFFEE_DTASTE));

	Dessert& dessert_ice_cream_crepe = Dessert(MenuItem(eItemId(CREPE_ICE_CREAM), "Delicious crepe with an ice cream on the side", 80, "milk, nuts, nutella"), eDessertSize(SMALL_DESSERT));
	IceCreamBall& iceCream_for_CrepeIceCream = IceCreamBall(dessert_ice_cream_crepe, eTaste(CHOCOLATE_DTASTE));
	Crepe& crepe_for_CrepeIceCream = Crepe(dessert_ice_cream_crepe, eSpread(NUTELLA_SPREAD_WITH_COCOS));
	CrepeWithIceCream& crepe_with_icecream = CrepeWithIceCream(crepe_for_CrepeIceCream, iceCream_for_CrepeIceCream);

	Dessert& dessert_ice_cream_waffle = Dessert(MenuItem(eItemId(ICE_CREAM_WITH_BELGIAN_WAFFLE), "Delicious belgian waffle with an ice cream on the side", 60, "milk, nuts, nutella"), eDessertSize(SMALL_DESSERT));
	IceCreamBall& iceCream_for_WaffleIceCream = IceCreamBall(dessert_ice_cream_crepe, eTaste(CHOCOLATE_DTASTE));
	BelgianWaffle& waffle_for_WaffleIceCream = BelgianWaffle(dessert_ice_cream_waffle, eSyrup(CHOCOLATE_SYRUP));
	IceCreamWithBelgianWaffle& icecream_waffle = IceCreamWithBelgianWaffle(iceCream_for_WaffleIceCream, waffle_for_WaffleIceCream);

	menu.addMenuItem(waffle);
	menu.addMenuItem(iceCream);
	menu.addMenuItem(milkshake);
	menu.addMenuItem(crepe);
	menu.addMenuItem(smoothie);
	menu.addMenuItem(icecream_waffle);
	menu.addMenuItem(crepe_with_icecream);
}

int main()
{
	{
		IceCreamShop shop("24/7 Ice", "Bney Efraim 3, Tel Aviv");
		Menu shopMenu = shop.getMenu();
		initMenu(shopMenu);

		cout << "Welcome to " << shop.getName() << endl << shopMenu << endl;

		Employee employee1("John", 50);
		Employee employee2("Jeff", 53);
		Employee employee3("Jim", 60);
		Employee employee4("Sarah", 20);

		Vendor vendor1(employee1);
		Vendor vendor2(employee2);

		shop.addEmployee(vendor1);
		shop.addEmployee(vendor2);
		shop.addEmployee(employee3);
		shop.addEmployee(employee4);

		Customer customer1("Donald");
		Customer customer2("Jessica");

		Order& customer1_order = customer1.createOrder();

		customer1_order.addItem(ICE_CREAM_WITH_BELGIAN_WAFFLE);
		customer1_order.addItem(SMOOTHIE);

		Employee* available_employee;
		Vendor* available_vendor = shop.getAvailableVendor();
		MenuItem* ready_items;
		int size_arr;
		if (available_vendor)
		{
			available_vendor->takeOrder(customer1_order);

			if (customer1_order.isOrderPaid())
			{
				available_employee = shop.getAvailableEmployee();
				if (available_employee)
				{
					available_employee->prepareOrder(customer1_order);
					size_arr = customer1_order.getReadyItems(&ready_items);
					for (int i = 0; i < size_arr; i++)
						cout << ready_items[i] << endl;
				}
			}
		}

		shop.removeEmployee(employee3.getID());
		shop.removeEmployee(employee4.getID());
		shop.removeEmployee(vendor1.getID());
		shop.removeEmployee(vendor2.getID());
	}
	system("pause");
	return 0;
}