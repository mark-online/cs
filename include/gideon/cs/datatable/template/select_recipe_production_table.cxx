// Copyright (c) 2005-2014 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version.
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file.
//

// Begin prologue.
//
#include <DataTablePCH.h>
//
// End prologue.

#include <xsd/cxx/pre.hxx>

#include "select_recipe_production_table.hxx"

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace gdt
{
  // select_recipe_production_t
  //

  select_recipe_production_t::
  select_recipe_production_t ()
  : ::xml_schema::type (),
    select_resources_production_code_ (this),
    recipe_code_1_ (this),
    max_count_1_ (this),
    recipe_code_2_ (this),
    max_count_2_ (this),
    recipe_code_3_ (this),
    max_count_3_ (this),
    recipe_code_4_ (this),
    max_count_4_ (this),
    recipe_code_5_ (this),
    max_count_5_ (this)
  {
  }

  select_recipe_production_t::
  select_recipe_production_t (const select_resources_production_code_type& select_resources_production_code,
                              const recipe_code_1_type& recipe_code_1,
                              const max_count_1_type& max_count_1,
                              const recipe_code_2_type& recipe_code_2,
                              const max_count_2_type& max_count_2,
                              const recipe_code_3_type& recipe_code_3,
                              const max_count_3_type& max_count_3,
                              const recipe_code_4_type& recipe_code_4,
                              const max_count_4_type& max_count_4,
                              const recipe_code_5_type& recipe_code_5,
                              const max_count_5_type& max_count_5)
  : ::xml_schema::type (),
    select_resources_production_code_ (select_resources_production_code, this),
    recipe_code_1_ (recipe_code_1, this),
    max_count_1_ (max_count_1, this),
    recipe_code_2_ (recipe_code_2, this),
    max_count_2_ (max_count_2, this),
    recipe_code_3_ (recipe_code_3, this),
    max_count_3_ (max_count_3, this),
    recipe_code_4_ (recipe_code_4, this),
    max_count_4_ (max_count_4, this),
    recipe_code_5_ (recipe_code_5, this),
    max_count_5_ (max_count_5, this)
  {
  }

  select_recipe_production_t::
  select_recipe_production_t (const select_recipe_production_t& x,
                              ::xml_schema::flags f,
                              ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    select_resources_production_code_ (x.select_resources_production_code_, f, this),
    recipe_code_1_ (x.recipe_code_1_, f, this),
    max_count_1_ (x.max_count_1_, f, this),
    recipe_code_2_ (x.recipe_code_2_, f, this),
    max_count_2_ (x.max_count_2_, f, this),
    recipe_code_3_ (x.recipe_code_3_, f, this),
    max_count_3_ (x.max_count_3_, f, this),
    recipe_code_4_ (x.recipe_code_4_, f, this),
    max_count_4_ (x.max_count_4_, f, this),
    recipe_code_5_ (x.recipe_code_5_, f, this),
    max_count_5_ (x.max_count_5_, f, this)
  {
  }

  select_recipe_production_t::
  select_recipe_production_t (const ::xercesc::DOMElement& e,
                              ::xml_schema::flags f,
                              ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    select_resources_production_code_ (this),
    recipe_code_1_ (this),
    max_count_1_ (this),
    recipe_code_2_ (this),
    max_count_2_ (this),
    recipe_code_3_ (this),
    max_count_3_ (this),
    recipe_code_4_ (this),
    max_count_4_ (this),
    recipe_code_5_ (this),
    max_count_5_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< wchar_t > p (e, false, false, true);
      this->parse (p, f);
    }
  }

  void select_recipe_production_t::
  parse (::xsd::cxx::xml::dom::parser< wchar_t >& p,
         ::xml_schema::flags f)
  {
    while (p.more_attributes ())
    {
      const ::xercesc::DOMAttr& i (p.next_attribute ());
      const ::xsd::cxx::xml::qualified_name< wchar_t > n (
        ::xsd::cxx::xml::dom::name< wchar_t > (i));

      if (n.name () == L"select_resources_production_code" && n.namespace_ ().empty ())
      {
        this->select_resources_production_code_.set (select_resources_production_code_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"recipe_code_1" && n.namespace_ ().empty ())
      {
        this->recipe_code_1_.set (recipe_code_1_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"max_count_1" && n.namespace_ ().empty ())
      {
        this->max_count_1_.set (max_count_1_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"recipe_code_2" && n.namespace_ ().empty ())
      {
        this->recipe_code_2_.set (recipe_code_2_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"max_count_2" && n.namespace_ ().empty ())
      {
        this->max_count_2_.set (max_count_2_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"recipe_code_3" && n.namespace_ ().empty ())
      {
        this->recipe_code_3_.set (recipe_code_3_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"max_count_3" && n.namespace_ ().empty ())
      {
        this->max_count_3_.set (max_count_3_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"recipe_code_4" && n.namespace_ ().empty ())
      {
        this->recipe_code_4_.set (recipe_code_4_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"max_count_4" && n.namespace_ ().empty ())
      {
        this->max_count_4_.set (max_count_4_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"recipe_code_5" && n.namespace_ ().empty ())
      {
        this->recipe_code_5_.set (recipe_code_5_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"max_count_5" && n.namespace_ ().empty ())
      {
        this->max_count_5_.set (max_count_5_traits::create (i, f, this));
        continue;
      }
    }

    if (!select_resources_production_code_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"select_resources_production_code",
        L"");
    }

    if (!recipe_code_1_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"recipe_code_1",
        L"");
    }

    if (!max_count_1_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"max_count_1",
        L"");
    }

    if (!recipe_code_2_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"recipe_code_2",
        L"");
    }

    if (!max_count_2_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"max_count_2",
        L"");
    }

    if (!recipe_code_3_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"recipe_code_3",
        L"");
    }

    if (!max_count_3_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"max_count_3",
        L"");
    }

    if (!recipe_code_4_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"recipe_code_4",
        L"");
    }

    if (!max_count_4_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"max_count_4",
        L"");
    }

    if (!recipe_code_5_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"recipe_code_5",
        L"");
    }

    if (!max_count_5_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"max_count_5",
        L"");
    }
  }

  select_recipe_production_t* select_recipe_production_t::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class select_recipe_production_t (*this, f, c);
  }

  select_recipe_production_t& select_recipe_production_t::
  operator= (const select_recipe_production_t& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->select_resources_production_code_ = x.select_resources_production_code_;
      this->recipe_code_1_ = x.recipe_code_1_;
      this->max_count_1_ = x.max_count_1_;
      this->recipe_code_2_ = x.recipe_code_2_;
      this->max_count_2_ = x.max_count_2_;
      this->recipe_code_3_ = x.recipe_code_3_;
      this->max_count_3_ = x.max_count_3_;
      this->recipe_code_4_ = x.recipe_code_4_;
      this->max_count_4_ = x.max_count_4_;
      this->recipe_code_5_ = x.recipe_code_5_;
      this->max_count_5_ = x.max_count_5_;
    }

    return *this;
  }

  select_recipe_production_t::
  ~select_recipe_production_t ()
  {
  }

  // select_recipe_production_table
  //

  select_recipe_production_table::
  select_recipe_production_table ()
  : ::xml_schema::type (),
    select_recipe_production_template_ (this)
  {
  }

  select_recipe_production_table::
  select_recipe_production_table (const select_recipe_production_table& x,
                                  ::xml_schema::flags f,
                                  ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    select_recipe_production_template_ (x.select_recipe_production_template_, f, this)
  {
  }

  select_recipe_production_table::
  select_recipe_production_table (const ::xercesc::DOMElement& e,
                                  ::xml_schema::flags f,
                                  ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    select_recipe_production_template_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< wchar_t > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void select_recipe_production_table::
  parse (::xsd::cxx::xml::dom::parser< wchar_t >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< wchar_t > n (
        ::xsd::cxx::xml::dom::name< wchar_t > (i));

      // select_recipe_production_template
      //
      if (n.name () == L"select_recipe_production_template" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< select_recipe_production_template_type > r (
          select_recipe_production_template_traits::create (i, f, this));

        this->select_recipe_production_template_.push_back (::std::move (r));
        continue;
      }

      break;
    }
  }

  select_recipe_production_table* select_recipe_production_table::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class select_recipe_production_table (*this, f, c);
  }

  select_recipe_production_table& select_recipe_production_table::
  operator= (const select_recipe_production_table& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->select_recipe_production_template_ = x.select_recipe_production_template_;
    }

    return *this;
  }

  select_recipe_production_table::
  ~select_recipe_production_table ()
  {
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace gdt
{
  ::std::unique_ptr< ::gdt::select_recipe_production_table >
  select_recipe_production_table_ (const ::std::wstring& u,
                                   ::xml_schema::flags f,
                                   const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::tree::error_handler< wchar_t > h;

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        u, h, p, f));

    h.throw_if_failed< ::xsd::cxx::tree::parsing< wchar_t > > ();

    return ::std::unique_ptr< ::gdt::select_recipe_production_table > (
      ::gdt::select_recipe_production_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::select_recipe_production_table >
  select_recipe_production_table_ (const ::std::wstring& u,
                                   ::xml_schema::error_handler& h,
                                   ::xml_schema::flags f,
                                   const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        u, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::select_recipe_production_table > (
      ::gdt::select_recipe_production_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::select_recipe_production_table >
  select_recipe_production_table_ (const ::std::wstring& u,
                                   ::xercesc::DOMErrorHandler& h,
                                   ::xml_schema::flags f,
                                   const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        u, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::select_recipe_production_table > (
      ::gdt::select_recipe_production_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::select_recipe_production_table >
  select_recipe_production_table_ (::std::istream& is,
                                   ::xml_schema::flags f,
                                   const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::select_recipe_production_table_ (isrc, f, p);
  }

  ::std::unique_ptr< ::gdt::select_recipe_production_table >
  select_recipe_production_table_ (::std::istream& is,
                                   ::xml_schema::error_handler& h,
                                   ::xml_schema::flags f,
                                   const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::select_recipe_production_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::select_recipe_production_table >
  select_recipe_production_table_ (::std::istream& is,
                                   ::xercesc::DOMErrorHandler& h,
                                   ::xml_schema::flags f,
                                   const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::select_recipe_production_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::select_recipe_production_table >
  select_recipe_production_table_ (::std::istream& is,
                                   const ::std::wstring& sid,
                                   ::xml_schema::flags f,
                                   const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::select_recipe_production_table_ (isrc, f, p);
  }

  ::std::unique_ptr< ::gdt::select_recipe_production_table >
  select_recipe_production_table_ (::std::istream& is,
                                   const ::std::wstring& sid,
                                   ::xml_schema::error_handler& h,
                                   ::xml_schema::flags f,
                                   const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::select_recipe_production_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::select_recipe_production_table >
  select_recipe_production_table_ (::std::istream& is,
                                   const ::std::wstring& sid,
                                   ::xercesc::DOMErrorHandler& h,
                                   ::xml_schema::flags f,
                                   const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::select_recipe_production_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::select_recipe_production_table >
  select_recipe_production_table_ (::xercesc::InputSource& i,
                                   ::xml_schema::flags f,
                                   const ::xml_schema::properties& p)
  {
    ::xsd::cxx::tree::error_handler< wchar_t > h;

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    h.throw_if_failed< ::xsd::cxx::tree::parsing< wchar_t > > ();

    return ::std::unique_ptr< ::gdt::select_recipe_production_table > (
      ::gdt::select_recipe_production_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::select_recipe_production_table >
  select_recipe_production_table_ (::xercesc::InputSource& i,
                                   ::xml_schema::error_handler& h,
                                   ::xml_schema::flags f,
                                   const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::select_recipe_production_table > (
      ::gdt::select_recipe_production_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::select_recipe_production_table >
  select_recipe_production_table_ (::xercesc::InputSource& i,
                                   ::xercesc::DOMErrorHandler& h,
                                   ::xml_schema::flags f,
                                   const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::select_recipe_production_table > (
      ::gdt::select_recipe_production_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::select_recipe_production_table >
  select_recipe_production_table_ (const ::xercesc::DOMDocument& doc,
                                   ::xml_schema::flags f,
                                   const ::xml_schema::properties& p)
  {
    if (f & ::xml_schema::flags::keep_dom)
    {
      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
        static_cast< ::xercesc::DOMDocument* > (doc.cloneNode (true)));

      return ::std::unique_ptr< ::gdt::select_recipe_production_table > (
        ::gdt::select_recipe_production_table_ (
          std::move (d), f | ::xml_schema::flags::own_dom, p));
    }

    const ::xercesc::DOMElement& e (*doc.getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< wchar_t > n (
      ::xsd::cxx::xml::dom::name< wchar_t > (e));

    if (n.name () == L"select_recipe_production_table" &&
        n.namespace_ () == L"")
    {
      ::std::unique_ptr< ::gdt::select_recipe_production_table > r (
        ::xsd::cxx::tree::traits< ::gdt::select_recipe_production_table, wchar_t >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
      n.name (),
      n.namespace_ (),
      L"select_recipe_production_table",
      L"");
  }

  ::std::unique_ptr< ::gdt::select_recipe_production_table >
  select_recipe_production_table_ (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
                                   ::xml_schema::flags f,
                                   const ::xml_schema::properties&)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > c (
      ((f & ::xml_schema::flags::keep_dom) &&
       !(f & ::xml_schema::flags::own_dom))
      ? static_cast< ::xercesc::DOMDocument* > (d->cloneNode (true))
      : 0);

    ::xercesc::DOMDocument& doc (c.get () ? *c : *d);
    const ::xercesc::DOMElement& e (*doc.getDocumentElement ());

    const ::xsd::cxx::xml::qualified_name< wchar_t > n (
      ::xsd::cxx::xml::dom::name< wchar_t > (e));

    if (f & ::xml_schema::flags::keep_dom)
      doc.setUserData (::xml_schema::dom::tree_node_key,
                       (c.get () ? &c : &d),
                       0);

    if (n.name () == L"select_recipe_production_table" &&
        n.namespace_ () == L"")
    {
      ::std::unique_ptr< ::gdt::select_recipe_production_table > r (
        ::xsd::cxx::tree::traits< ::gdt::select_recipe_production_table, wchar_t >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
      n.name (),
      n.namespace_ (),
      L"select_recipe_production_table",
      L"");
  }
}

#include <ostream>
#include <xsd/cxx/tree/error-handler.hxx>
#include <xsd/cxx/xml/dom/serialization-source.hxx>

namespace gdt
{
  void
  select_recipe_production_table_ (::std::ostream& o,
                                   const ::gdt::select_recipe_production_table& s,
                                   const ::xml_schema::namespace_infomap& m,
                                   const ::std::wstring& e,
                                   ::xml_schema::flags f)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0);

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::select_recipe_production_table_ (s, m, f));

    ::xsd::cxx::tree::error_handler< wchar_t > h;

    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      h.throw_if_failed< ::xsd::cxx::tree::serialization< wchar_t > > ();
    }
  }

  void
  select_recipe_production_table_ (::std::ostream& o,
                                   const ::gdt::select_recipe_production_table& s,
                                   ::xml_schema::error_handler& h,
                                   const ::xml_schema::namespace_infomap& m,
                                   const ::std::wstring& e,
                                   ::xml_schema::flags f)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0);

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::select_recipe_production_table_ (s, m, f));
    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  select_recipe_production_table_ (::std::ostream& o,
                                   const ::gdt::select_recipe_production_table& s,
                                   ::xercesc::DOMErrorHandler& h,
                                   const ::xml_schema::namespace_infomap& m,
                                   const ::std::wstring& e,
                                   ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::select_recipe_production_table_ (s, m, f));
    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  select_recipe_production_table_ (::xercesc::XMLFormatTarget& t,
                                   const ::gdt::select_recipe_production_table& s,
                                   const ::xml_schema::namespace_infomap& m,
                                   const ::std::wstring& e,
                                   ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::select_recipe_production_table_ (s, m, f));

    ::xsd::cxx::tree::error_handler< wchar_t > h;

    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      h.throw_if_failed< ::xsd::cxx::tree::serialization< wchar_t > > ();
    }
  }

  void
  select_recipe_production_table_ (::xercesc::XMLFormatTarget& t,
                                   const ::gdt::select_recipe_production_table& s,
                                   ::xml_schema::error_handler& h,
                                   const ::xml_schema::namespace_infomap& m,
                                   const ::std::wstring& e,
                                   ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::select_recipe_production_table_ (s, m, f));
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  select_recipe_production_table_ (::xercesc::XMLFormatTarget& t,
                                   const ::gdt::select_recipe_production_table& s,
                                   ::xercesc::DOMErrorHandler& h,
                                   const ::xml_schema::namespace_infomap& m,
                                   const ::std::wstring& e,
                                   ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::select_recipe_production_table_ (s, m, f));
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  select_recipe_production_table_ (::xercesc::DOMDocument& d,
                                   const ::gdt::select_recipe_production_table& s,
                                   ::xml_schema::flags)
  {
    ::xercesc::DOMElement& e (*d.getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< wchar_t > n (
      ::xsd::cxx::xml::dom::name< wchar_t > (e));

    if (n.name () == L"select_recipe_production_table" &&
        n.namespace_ () == L"")
    {
      e << s;
    }
    else
    {
      throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
        n.name (),
        n.namespace_ (),
        L"select_recipe_production_table",
        L"");
    }
  }

  ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
  select_recipe_production_table_ (const ::gdt::select_recipe_production_table& s,
                                   const ::xml_schema::namespace_infomap& m,
                                   ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::serialize< wchar_t > (
        L"select_recipe_production_table",
        L"",
        m, f));

    ::gdt::select_recipe_production_table_ (*d, s, f);
    return d;
  }

  void
  operator<< (::xercesc::DOMElement& e, const select_recipe_production_t& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // select_resources_production_code
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"select_resources_production_code",
          e));

      a << i.select_resources_production_code ();
    }

    // recipe_code_1
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"recipe_code_1",
          e));

      a << i.recipe_code_1 ();
    }

    // max_count_1
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"max_count_1",
          e));

      a << i.max_count_1 ();
    }

    // recipe_code_2
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"recipe_code_2",
          e));

      a << i.recipe_code_2 ();
    }

    // max_count_2
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"max_count_2",
          e));

      a << i.max_count_2 ();
    }

    // recipe_code_3
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"recipe_code_3",
          e));

      a << i.recipe_code_3 ();
    }

    // max_count_3
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"max_count_3",
          e));

      a << i.max_count_3 ();
    }

    // recipe_code_4
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"recipe_code_4",
          e));

      a << i.recipe_code_4 ();
    }

    // max_count_4
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"max_count_4",
          e));

      a << i.max_count_4 ();
    }

    // recipe_code_5
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"recipe_code_5",
          e));

      a << i.recipe_code_5 ();
    }

    // max_count_5
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"max_count_5",
          e));

      a << i.max_count_5 ();
    }
  }

  void
  operator<< (::xercesc::DOMElement& e, const select_recipe_production_table& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // select_recipe_production_template
    //
    for (select_recipe_production_table::select_recipe_production_template_const_iterator
         b (i.select_recipe_production_template ().begin ()), n (i.select_recipe_production_template ().end ());
         b != n; ++b)
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          L"select_recipe_production_template",
          e));

      s << *b;
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.
