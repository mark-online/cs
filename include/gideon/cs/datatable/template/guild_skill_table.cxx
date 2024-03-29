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

#include "guild_skill_table.hxx"

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace gdt
{
  // guild_skill_t
  //

  guild_skill_t::
  guild_skill_t ()
  : ::xml_schema::type (),
    skill_code_ (this),
    consume_sp_ (this),
    need_level_ (this),
    effect_script_type_ (this),
    effect_value_ (this),
    icon_name_ (this)
  {
  }

  guild_skill_t::
  guild_skill_t (const skill_code_type& skill_code,
                 const consume_sp_type& consume_sp,
                 const need_level_type& need_level,
                 const effect_script_type_type& effect_script_type,
                 const effect_value_type& effect_value,
                 const icon_name_type& icon_name)
  : ::xml_schema::type (),
    skill_code_ (skill_code, this),
    consume_sp_ (consume_sp, this),
    need_level_ (need_level, this),
    effect_script_type_ (effect_script_type, this),
    effect_value_ (effect_value, this),
    icon_name_ (icon_name, this)
  {
  }

  guild_skill_t::
  guild_skill_t (const guild_skill_t& x,
                 ::xml_schema::flags f,
                 ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    skill_code_ (x.skill_code_, f, this),
    consume_sp_ (x.consume_sp_, f, this),
    need_level_ (x.need_level_, f, this),
    effect_script_type_ (x.effect_script_type_, f, this),
    effect_value_ (x.effect_value_, f, this),
    icon_name_ (x.icon_name_, f, this)
  {
  }

  guild_skill_t::
  guild_skill_t (const ::xercesc::DOMElement& e,
                 ::xml_schema::flags f,
                 ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    skill_code_ (this),
    consume_sp_ (this),
    need_level_ (this),
    effect_script_type_ (this),
    effect_value_ (this),
    icon_name_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< wchar_t > p (e, false, false, true);
      this->parse (p, f);
    }
  }

  void guild_skill_t::
  parse (::xsd::cxx::xml::dom::parser< wchar_t >& p,
         ::xml_schema::flags f)
  {
    while (p.more_attributes ())
    {
      const ::xercesc::DOMAttr& i (p.next_attribute ());
      const ::xsd::cxx::xml::qualified_name< wchar_t > n (
        ::xsd::cxx::xml::dom::name< wchar_t > (i));

      if (n.name () == L"skill_code" && n.namespace_ ().empty ())
      {
        this->skill_code_.set (skill_code_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"consume_sp" && n.namespace_ ().empty ())
      {
        this->consume_sp_.set (consume_sp_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"need_level" && n.namespace_ ().empty ())
      {
        this->need_level_.set (need_level_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"effect_script_type" && n.namespace_ ().empty ())
      {
        this->effect_script_type_.set (effect_script_type_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"effect_value" && n.namespace_ ().empty ())
      {
        this->effect_value_.set (effect_value_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"icon_name" && n.namespace_ ().empty ())
      {
        this->icon_name_.set (icon_name_traits::create (i, f, this));
        continue;
      }
    }

    if (!skill_code_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"skill_code",
        L"");
    }

    if (!consume_sp_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"consume_sp",
        L"");
    }

    if (!need_level_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"need_level",
        L"");
    }

    if (!effect_script_type_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"effect_script_type",
        L"");
    }

    if (!effect_value_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"effect_value",
        L"");
    }

    if (!icon_name_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"icon_name",
        L"");
    }
  }

  guild_skill_t* guild_skill_t::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class guild_skill_t (*this, f, c);
  }

  guild_skill_t& guild_skill_t::
  operator= (const guild_skill_t& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->skill_code_ = x.skill_code_;
      this->consume_sp_ = x.consume_sp_;
      this->need_level_ = x.need_level_;
      this->effect_script_type_ = x.effect_script_type_;
      this->effect_value_ = x.effect_value_;
      this->icon_name_ = x.icon_name_;
    }

    return *this;
  }

  guild_skill_t::
  ~guild_skill_t ()
  {
  }

  // guild_skill_table
  //

  guild_skill_table::
  guild_skill_table ()
  : ::xml_schema::type (),
    guild_skill_template_ (this)
  {
  }

  guild_skill_table::
  guild_skill_table (const guild_skill_table& x,
                     ::xml_schema::flags f,
                     ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    guild_skill_template_ (x.guild_skill_template_, f, this)
  {
  }

  guild_skill_table::
  guild_skill_table (const ::xercesc::DOMElement& e,
                     ::xml_schema::flags f,
                     ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    guild_skill_template_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< wchar_t > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void guild_skill_table::
  parse (::xsd::cxx::xml::dom::parser< wchar_t >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< wchar_t > n (
        ::xsd::cxx::xml::dom::name< wchar_t > (i));

      // guild_skill_template
      //
      if (n.name () == L"guild_skill_template" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< guild_skill_template_type > r (
          guild_skill_template_traits::create (i, f, this));

        this->guild_skill_template_.push_back (::std::move (r));
        continue;
      }

      break;
    }
  }

  guild_skill_table* guild_skill_table::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class guild_skill_table (*this, f, c);
  }

  guild_skill_table& guild_skill_table::
  operator= (const guild_skill_table& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->guild_skill_template_ = x.guild_skill_template_;
    }

    return *this;
  }

  guild_skill_table::
  ~guild_skill_table ()
  {
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace gdt
{
  ::std::unique_ptr< ::gdt::guild_skill_table >
  guild_skill_table_ (const ::std::wstring& u,
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

    return ::std::unique_ptr< ::gdt::guild_skill_table > (
      ::gdt::guild_skill_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::guild_skill_table >
  guild_skill_table_ (const ::std::wstring& u,
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

    return ::std::unique_ptr< ::gdt::guild_skill_table > (
      ::gdt::guild_skill_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::guild_skill_table >
  guild_skill_table_ (const ::std::wstring& u,
                      ::xercesc::DOMErrorHandler& h,
                      ::xml_schema::flags f,
                      const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        u, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::guild_skill_table > (
      ::gdt::guild_skill_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::guild_skill_table >
  guild_skill_table_ (::std::istream& is,
                      ::xml_schema::flags f,
                      const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::guild_skill_table_ (isrc, f, p);
  }

  ::std::unique_ptr< ::gdt::guild_skill_table >
  guild_skill_table_ (::std::istream& is,
                      ::xml_schema::error_handler& h,
                      ::xml_schema::flags f,
                      const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::guild_skill_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::guild_skill_table >
  guild_skill_table_ (::std::istream& is,
                      ::xercesc::DOMErrorHandler& h,
                      ::xml_schema::flags f,
                      const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::guild_skill_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::guild_skill_table >
  guild_skill_table_ (::std::istream& is,
                      const ::std::wstring& sid,
                      ::xml_schema::flags f,
                      const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::guild_skill_table_ (isrc, f, p);
  }

  ::std::unique_ptr< ::gdt::guild_skill_table >
  guild_skill_table_ (::std::istream& is,
                      const ::std::wstring& sid,
                      ::xml_schema::error_handler& h,
                      ::xml_schema::flags f,
                      const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::guild_skill_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::guild_skill_table >
  guild_skill_table_ (::std::istream& is,
                      const ::std::wstring& sid,
                      ::xercesc::DOMErrorHandler& h,
                      ::xml_schema::flags f,
                      const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::guild_skill_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::guild_skill_table >
  guild_skill_table_ (::xercesc::InputSource& i,
                      ::xml_schema::flags f,
                      const ::xml_schema::properties& p)
  {
    ::xsd::cxx::tree::error_handler< wchar_t > h;

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    h.throw_if_failed< ::xsd::cxx::tree::parsing< wchar_t > > ();

    return ::std::unique_ptr< ::gdt::guild_skill_table > (
      ::gdt::guild_skill_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::guild_skill_table >
  guild_skill_table_ (::xercesc::InputSource& i,
                      ::xml_schema::error_handler& h,
                      ::xml_schema::flags f,
                      const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::guild_skill_table > (
      ::gdt::guild_skill_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::guild_skill_table >
  guild_skill_table_ (::xercesc::InputSource& i,
                      ::xercesc::DOMErrorHandler& h,
                      ::xml_schema::flags f,
                      const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::guild_skill_table > (
      ::gdt::guild_skill_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::guild_skill_table >
  guild_skill_table_ (const ::xercesc::DOMDocument& doc,
                      ::xml_schema::flags f,
                      const ::xml_schema::properties& p)
  {
    if (f & ::xml_schema::flags::keep_dom)
    {
      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
        static_cast< ::xercesc::DOMDocument* > (doc.cloneNode (true)));

      return ::std::unique_ptr< ::gdt::guild_skill_table > (
        ::gdt::guild_skill_table_ (
          std::move (d), f | ::xml_schema::flags::own_dom, p));
    }

    const ::xercesc::DOMElement& e (*doc.getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< wchar_t > n (
      ::xsd::cxx::xml::dom::name< wchar_t > (e));

    if (n.name () == L"guild_skill_table" &&
        n.namespace_ () == L"")
    {
      ::std::unique_ptr< ::gdt::guild_skill_table > r (
        ::xsd::cxx::tree::traits< ::gdt::guild_skill_table, wchar_t >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
      n.name (),
      n.namespace_ (),
      L"guild_skill_table",
      L"");
  }

  ::std::unique_ptr< ::gdt::guild_skill_table >
  guild_skill_table_ (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
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

    if (n.name () == L"guild_skill_table" &&
        n.namespace_ () == L"")
    {
      ::std::unique_ptr< ::gdt::guild_skill_table > r (
        ::xsd::cxx::tree::traits< ::gdt::guild_skill_table, wchar_t >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
      n.name (),
      n.namespace_ (),
      L"guild_skill_table",
      L"");
  }
}

#include <ostream>
#include <xsd/cxx/tree/error-handler.hxx>
#include <xsd/cxx/xml/dom/serialization-source.hxx>

namespace gdt
{
  void
  guild_skill_table_ (::std::ostream& o,
                      const ::gdt::guild_skill_table& s,
                      const ::xml_schema::namespace_infomap& m,
                      const ::std::wstring& e,
                      ::xml_schema::flags f)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0);

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::guild_skill_table_ (s, m, f));

    ::xsd::cxx::tree::error_handler< wchar_t > h;

    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      h.throw_if_failed< ::xsd::cxx::tree::serialization< wchar_t > > ();
    }
  }

  void
  guild_skill_table_ (::std::ostream& o,
                      const ::gdt::guild_skill_table& s,
                      ::xml_schema::error_handler& h,
                      const ::xml_schema::namespace_infomap& m,
                      const ::std::wstring& e,
                      ::xml_schema::flags f)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0);

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::guild_skill_table_ (s, m, f));
    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  guild_skill_table_ (::std::ostream& o,
                      const ::gdt::guild_skill_table& s,
                      ::xercesc::DOMErrorHandler& h,
                      const ::xml_schema::namespace_infomap& m,
                      const ::std::wstring& e,
                      ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::guild_skill_table_ (s, m, f));
    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  guild_skill_table_ (::xercesc::XMLFormatTarget& t,
                      const ::gdt::guild_skill_table& s,
                      const ::xml_schema::namespace_infomap& m,
                      const ::std::wstring& e,
                      ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::guild_skill_table_ (s, m, f));

    ::xsd::cxx::tree::error_handler< wchar_t > h;

    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      h.throw_if_failed< ::xsd::cxx::tree::serialization< wchar_t > > ();
    }
  }

  void
  guild_skill_table_ (::xercesc::XMLFormatTarget& t,
                      const ::gdt::guild_skill_table& s,
                      ::xml_schema::error_handler& h,
                      const ::xml_schema::namespace_infomap& m,
                      const ::std::wstring& e,
                      ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::guild_skill_table_ (s, m, f));
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  guild_skill_table_ (::xercesc::XMLFormatTarget& t,
                      const ::gdt::guild_skill_table& s,
                      ::xercesc::DOMErrorHandler& h,
                      const ::xml_schema::namespace_infomap& m,
                      const ::std::wstring& e,
                      ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::guild_skill_table_ (s, m, f));
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  guild_skill_table_ (::xercesc::DOMDocument& d,
                      const ::gdt::guild_skill_table& s,
                      ::xml_schema::flags)
  {
    ::xercesc::DOMElement& e (*d.getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< wchar_t > n (
      ::xsd::cxx::xml::dom::name< wchar_t > (e));

    if (n.name () == L"guild_skill_table" &&
        n.namespace_ () == L"")
    {
      e << s;
    }
    else
    {
      throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
        n.name (),
        n.namespace_ (),
        L"guild_skill_table",
        L"");
    }
  }

  ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
  guild_skill_table_ (const ::gdt::guild_skill_table& s,
                      const ::xml_schema::namespace_infomap& m,
                      ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::serialize< wchar_t > (
        L"guild_skill_table",
        L"",
        m, f));

    ::gdt::guild_skill_table_ (*d, s, f);
    return d;
  }

  void
  operator<< (::xercesc::DOMElement& e, const guild_skill_t& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // skill_code
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"skill_code",
          e));

      a << i.skill_code ();
    }

    // consume_sp
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"consume_sp",
          e));

      a << i.consume_sp ();
    }

    // need_level
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"need_level",
          e));

      a << i.need_level ();
    }

    // effect_script_type
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"effect_script_type",
          e));

      a << i.effect_script_type ();
    }

    // effect_value
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"effect_value",
          e));

      a << i.effect_value ();
    }

    // icon_name
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"icon_name",
          e));

      a << i.icon_name ();
    }
  }

  void
  operator<< (::xercesc::DOMElement& e, const guild_skill_table& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // guild_skill_template
    //
    for (guild_skill_table::guild_skill_template_const_iterator
         b (i.guild_skill_template ().begin ()), n (i.guild_skill_template ().end ());
         b != n; ++b)
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          L"guild_skill_template",
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

