
// ChildFrm.h : interface of the CChildFrame class
//

#pragma once


/// <summary>User interface</summary>
NAMESPACE_BEGIN(GUI)

   /// <summary>Child frame</summary>
   class CChildFrame : public CMDIChildWndEx
   {
	   DECLARE_DYNCREATE(CChildFrame)
   public:
	   CChildFrame();

   // Attributes
   public:

   // Operations
   public:

   // Overrides
	   virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

   // Implementation
   public:
	   virtual ~CChildFrame();
   #ifdef _DEBUG
	   virtual void AssertValid() const;
	   virtual void Dump(CDumpContext& dc) const;
   #endif

   // Generated message map functions
   protected:
	   DECLARE_MESSAGE_MAP()
   };


NAMESPACE_END(GUI)
