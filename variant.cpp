#include "Variant.h"
#include <sstream>
// Usar espacio de nombres específico de json11 si es necesario.

Variant::Variant(variant_type type) : type(type), env(nullptr), proc(nullptr) {}

Variant::Variant(variant_type type, const std::string& val) : type(type), val(val), env(nullptr), proc(nullptr) {}

Variant::Variant(proc_type proc) : type(Proc), proc(proc), env(nullptr) {}

std::string Variant::to_string() {
    switch (type) {
        case Symbol:
        case Number:
        case Cadena:
            return val;
        case List: {
            std::ostringstream oss;
            oss << "(";
            for (auto it = list.begin(); it != list.end(); ++it) {
                oss << it->to_string();
                if (it + 1 != list.end()) oss << " ";
            }
            oss << ")";
            return oss.str();
        }
        case Proc:
            return "<proc>";
        case Lambda:
            return "<lambda>";
        default:
            return "<unknown>";
    }
}

std::string Variant::to_json_string() {
    switch (type) {
        case Symbol:
        case Number:
        case Cadena:
            return json11::Json(val).dump();
        case List: {
            std::vector<json11::Json> jsonList;
            for (const Variant& v : list) {
                jsonList.push_back(json11::Json::parse(v.to_json_string(), nullptr));
            }
            return json11::Json(jsonList).dump();
        }
        case Proc:
        case Lambda:
            return "\"<function>\"";
        default:
            return "\"<unknown>\"";
    }
}

Variant Variant::from_json_string(const std::string& sjson) {
    std::string err;
    json11::Json jobj = json11::Json::parse(sjson, err);
    if (!err.empty()) {
        throw std::runtime_error("Invalid JSON string");
    }
    return parse_json(jobj);
}

Variant Variant::parse_json(const json11::Json& job) {
    if (job.is_string()) {
        return Variant(Cadena, job.string_value());
    } else if (job.is_number()) {
        return Variant(Number, std::to_string(job.number_value()));
    } else if (job.is_array()) {
        Variant variantList(List);
        for (const auto& item : job.array_items()) {
            variantList.list.push_back(parse_json(item));
        }
        return variantList;
    }
    throw std::runtime_error("Unsupported JSON type");
}