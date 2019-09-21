#pragma once
#ifndef _ORDER_H
#include "Vendor.h"
#include "Date.h"
#include "MenuItem.h"
#include <iostream>
using namespace std;

class Order
{
	static int next_id;
	const int orderID;
	const Date creationDate;
	int num_items_ready;
	bool isPaid;
	/* items for the customers returned here */
	MenuItem* ready_items;
	eItemId* items_ordered;
public:
	Order();
	Order(Order& order);
	virtual ~Order();

	int addItem(eItemId itemID) const;
	int removeItem(int itemID) const;
	double calculateTotal() const;

	int getOrderID()  const;
	const Date getCreationDate() const;

	bool isOrderPaid() const;
	void setPaid(bool pay);

	int getNumItemsReady() const;
	void setNumItemsReady(int num);

	/* returns pointer to prepared items, function returns size of array */
	int getReadyItems(MenuItem** items) const;

	friend ostream& operator<<(ostream& os, const Order& order);
	Order& operator+(const Order& order) const;

	bool operator==(const Order& order) const;
	bool operator!=(const Order& order) const;
	bool operator>(const Order& order) const;
	bool operator<(const Order& order) const;
	bool operator>=(const Order& order) const;
	bool operator<=(const Order& order) const;
};

int Order::next_id = 0;

#endif //!_ORDER_H