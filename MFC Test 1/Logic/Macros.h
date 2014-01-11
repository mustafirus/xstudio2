#pragma once

// Macro: Creates a wide char equivilent of an input string (from MSDN)
#define WIDEN2(x)                L ## x
#define WIDEN(x)                 WIDEN2(x)

// Macro: Wide character equivilent of __FILE__
#define __WFILE__                WIDEN(__FILE__)

// Macro: Wide character equivilent of __FUNCTION__
#define __WFUNCTION__            WIDEN(__FUNCTION__)


// Macro: Provides default move constructor and assignment (Not functional)
#define DEFAULT_MOVE(type)       // MS BUG:800114:     type::type(type&&) = default;  type& operator=(type&&) = default;

// Macro: Provides default copy constructor and assignment
#define DEFAULT_COPY(type)       type::type(const type&) = default;  type& operator=(const type&) = default;


// Macro: Prevents a class from being moved
#define NO_MOVE(type)            type::type(type&&) = delete;  NO_MOVE_ASSIGN(type)

// Macro: Prevents a class from being copied
#define NO_COPY(type)            type::type(const type&) = delete;  NO_COPY_ASSIGN(type)

// Macro: Disables move assignment operator
#define NO_MOVE_ASSIGN(type)     type& operator=(type&&) = delete;

// Macro: Disables copy assignment operator
#define NO_COPY_ASSIGN(type)     type& operator=(const type&) = delete;


// Macro: Declares a read-only property 
#define PROPERTY_GET(type,name,fget)   __declspec(property(get=fget)) type name

// Macro: Declares a read-write property 
#define PROPERTY_GET_SET(type,name,fget,fset)   __declspec(property(get=fget,put=fset)) type name