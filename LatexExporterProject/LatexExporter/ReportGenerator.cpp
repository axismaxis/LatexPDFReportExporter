#include "pch.h"
#include "ReportGenerator.h"
#include <sstream>
#include <fstream>


void ReportGenerator::ExportToPdf()
{
	std::stringstream ss;
	ss << "\\documentclass{article}\n\\usepackage{ graphicx }\n\\title{ My first document }\n\\date{ 2013 - 09 - 01 }\n\\author{ John Doe }";
	ss << "\n\\begin{document}";
	ss << "\n\\maketitle";
	ss << "\n\\newpage";

	for (Element* element : report->elements)
	{
		ss << "\n\\begin{center}";
		ss << "\n\\makebox[\\textwidth]{\\includegraphics[width=\\paperwidth]{" << element->ImagePath << "}}";
		ss << "\n" << element->ImageDescription;
		ss << "\n\\end{center}";
	}

	ss << "\n\\end{document}";

	std::ofstream oFile;
	oFile.open("output.tex");
	oFile << ss.str();
	oFile.close();

	LatexPDFExporter exporter("\\Program Files\\MiKTeX 2.9\\miktex\\bin\\x64\\pdflatex.exe");
	exporter.ExportLatexToPdf("output.tex");
}

void ReportGenerator::AddImageEntry(const char * imagePath, const char * imageDescription)
{
	Element* element = new Element;
	element->ImagePath = imagePath;
	element->ImageDescription = imageDescription;
	element->Location = "Not specified";

	report->elements.push_back(element);
}

ReportGenerator::ReportGenerator(const char* title, const char* summary)
{
	report = new Report();
}

ReportGenerator::~ReportGenerator()
{
}
