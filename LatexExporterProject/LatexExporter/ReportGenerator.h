#pragma once
#include <vector>
#include "LatexPDFExporter.h"

struct Element
{
	const char* ImagePath;
	const char* ImageDescription;
	const char* Location;
};

struct Report 
{
	const char* Title;
	const char* Summary;

	std::vector<Element*> elements;
};

class ReportGenerator
{
private:
	Report* report;
public:
	void ExportToPdf();
	void AddImageEntry(const char* imagePath, const char* imageDescription);

	ReportGenerator(const char* title, const char* summary);
	~ReportGenerator();
};

