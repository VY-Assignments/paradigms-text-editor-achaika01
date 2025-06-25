#include "Headers/TextLine.h"
#include "Headers/CheckListLine.h"
#include "Headers/ContactLine.h"

Line* Line::deserialize(const std::vector<std::byte>& data) {
	if (data.empty()) return nullptr;

	LineType type = static_cast<LineType>(data[0]);

	switch (type) {
	case LineType::TextLine:
		return TextLine::deserialize(data.data(), data.size());
		break;
	case LineType::CheckListLine:
		//return CheckListLine::deserialize(data.data(), data.size());
		break;
	case LineType::ContactLine:
		//return ContactLine::deserialize(data.data(), data.size());
		break;
	default:
		return nullptr;
	}
}