#pragma once

class Cloneable {
public: 
	/**
	 * @brief 
	 * returns deep copy.
	 * @return 
	 * the copy of itself.
	*/
	virtual Cloneable* clone() abstract;
};