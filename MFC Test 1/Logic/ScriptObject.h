#pragma once

#include "Common.h"
#include "LanguagePage.h"

namespace Logic
{
   namespace Scripts
   {
      /// <summary>Defines script object group</summary>
      enum class ScriptObjectGroup
      {
         Constant, DataType, FlightReturn, ObjectClass, Race, Relation, ParameterType, 
         Sector, StationSerial, ObjectCommand, WingCommand, Signal, TransportClass, Operator
      };

      /// <summary>Get script object group name</summary>
      GuiString GetString(const ScriptObjectGroup& g);

      /// <summary>Post-Increment script object group</summary>
      ScriptObjectGroup operator++(ScriptObjectGroup& g, int);

      /// <summary>Pre-Increment script object group</summary>
      ScriptObjectGroup& operator++(ScriptObjectGroup& g);

      /// <summary>Substract script object group as int</summary>
      UINT operator-(const ScriptObjectGroup& a, const ScriptObjectGroup& b);
      
      


      /// <summary>Represents a script object</summary>
      class ScriptObject 
      {
         // --------------------- CONSTRUCTION ----------------------
      public:
         ScriptObject(UINT id, KnownPage page, const wstring& txt, GameVersion ver);
         ~ScriptObject();

      private:
         ScriptObject(const ScriptObject& obj, const wstring& newText);
         

      public:
         DEFAULT_COPY(ScriptObject);	// Default copy semantics
		   DEFAULT_MOVE(ScriptObject);	// Default move semantics

         // ------------------------ STATIC -------------------------

         /// <summary>Identifies the script object group</summary>
         static ScriptObjectGroup  IdentifyGroup(KnownPage page, UINT id);

         // ---------------------- ACCESSORS ------------------------	

         // ----------------------- MUTATORS ------------------------
      public:
         /// <summary>Appends an object ID</summary>
         /// <param name="id">The id</param>
         /// <returns>script object with new text</returns>
         ScriptObject operator+(UINT id);

         /// <summary>Appends a game version acronym</summary>
         /// <param name="v">The version</param>
         /// <returns>script object with new text</returns>
         ScriptObject operator+(GameVersion v);

         /// <summary>Appends a group acronym</summary>
         /// <param name="g">The group</param>
         /// <returns>script object with new text</returns>
         /// <exception cref="Logic::ArgumentException">Incompatible page</exception>
         ScriptObject operator+(ScriptObjectGroup g);

         // -------------------- REPRESENTATION ---------------------
      public:
         const UINT              ID;
         const ScriptObjectGroup Group;
         wstring                 Text;
         GameVersion             Version;
      };


      /// <summary>Vector of script objects</summary>
      typedef vector<ScriptObject>  ScriptObjectArray;
   
   }
}

using namespace Logic::Scripts;