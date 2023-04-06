
#include <iostream>
#include <vector>


class IStock {
public:
	IStock(std::string stockType) : _stockType(stockType){}
	virtual void useStock(IStock* stock) = 0;
	virtual void addGoods(IStock* goods) = 0;
	void setNewGoods(std::string& goods) {
		_newGoods = goods;
	}
	virtual ~IStock() {};

protected:
	std::string _stockType;
	std::string _newGoods;
};


class SectionA : public IStock {
public:

	SectionA(std::string stockType) : IStock(stockType) {}
	void useStock(IStock* stock) override {
		std::cout << _stockType << std::endl;
	}
	void addGoods(IStock* goods) override {}
};


class SectionB : public IStock {
public:
	SectionB(std::string  _stockType) : IStock(_stockType){}
	void addGoods(IStock* goods) override {
		goods->setNewGoods(this->_newGoods);
		_goods.push_back(goods);
	}
	void useStock(IStock* stock) override {
		std::cout << _stockType << std::endl;
	}

private:
	std::vector<IStock*> _goods;

};




int main() {
	setlocale(LC_ALL, "Russian");

	IStock* sectionB = new SectionB("SectionB");

	IStock* addStock = new SectionB("SectionB1");

	sectionB->addGoods(addStock);

	IStock* stock = new SectionA("Stock");

	addStock->addGoods(stock);

	stock->useStock(stock);




















	return 0;
}