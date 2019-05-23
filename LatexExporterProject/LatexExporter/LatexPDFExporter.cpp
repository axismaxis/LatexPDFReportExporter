#include "pch.h"
#include "LatexPDFExporter.h"
#include <sstream>
#include <iostream>
#include <fstream>


void LatexPDFExporter::ExportLatexToPdf(std::string latexContentFile)
{
	std::string PDFLatexCommand = "\"" + PDFLatexExecutablePath + "\" " + latexContentFile + " & pause";
	std::cout << "Executing command: " << PDFLatexCommand << std::endl;
	system(PDFLatexCommand.c_str());
}

LatexPDFExporter::LatexPDFExporter(std::string PDFLatexExecutablePath) : 
	PDFLatexExecutablePath(PDFLatexExecutablePath)
{}


LatexPDFExporter::~LatexPDFExporter()
{
}
