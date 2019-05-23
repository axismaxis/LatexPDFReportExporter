#include "pch.h"
#include "pch.h"
#include <string>
#include "ReportGenerator.h"

int main()
{
	ReportGenerator report("Security report", "This document contains information about the investigation");

	report.AddImageEntry("image1.jpg", "Table is here");
	report.AddImageEntry("image2.jpg", "Chair is here");
	report.AddImageEntry("image3.jpg", "Lamp is here");

	report.ExportToPdf();

	return 0;
}

