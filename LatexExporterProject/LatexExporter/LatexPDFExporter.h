#pragma once
#include<string>

class LatexPDFExporter
{
private:
	std::string PDFLatexExecutablePath;
public:
	void ExportLatexToPdf(std::string latexContentFile);
	LatexPDFExporter(std::string pathToPDFLatexExecutable);
	~LatexPDFExporter();
};

