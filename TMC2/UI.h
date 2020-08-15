#pragma once
#include "List.h"

class List;

class UI
{
public:
	UI(List* main);

	void Add() const;
	void PrintAllNode() const;
	void DeleteAllNode() const;
	void DeleteNode() const;
	void Search() const;
	void Random(void) const;

	void choosemenu(void) const;

private:
	List* UI_main;
};

