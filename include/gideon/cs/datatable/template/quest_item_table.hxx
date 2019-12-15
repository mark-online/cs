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

/**
 * @file
 * @brief Generated from quest_item_table.xsd.
 */

#ifndef GDT_QUEST_ITEM_TABLE_HXX
#define GDT_QUEST_ITEM_TABLE_HXX

#ifndef XSD_CXX11
#define XSD_CXX11
#endif

#ifndef XSD_USE_WCHAR
#define XSD_USE_WCHAR
#endif

#ifndef XSD_CXX_TREE_USE_WCHAR
#define XSD_CXX_TREE_USE_WCHAR
#endif

// Begin prologue.
//
#include "shared_types.hxx"
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 4000000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

#include "xml_schema.hxx"

// Forward declarations.
//
namespace gdt
{
  class quest_item_t;
  class quest_item_table;
}


#include <memory>    // ::std::unique_ptr
#include <limits>    // std::numeric_limits
#include <algorithm> // std::binary_search
#include <utility>   // std::move

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/containers.hxx>
#include <xsd/cxx/tree/list.hxx>

#include <xsd/cxx/xml/dom/parsing-header.hxx>

#ifndef XSD_DONT_INCLUDE_INLINE
#define XSD_DONT_INCLUDE_INLINE

#include "shared_types.hxx"

#undef XSD_DONT_INCLUDE_INLINE
#else

#include "shared_types.hxx"

#endif // XSD_DONT_INCLUDE_INLINE

/**
 * @brief C++ namespace for the %
 * schema namespace.
 */
namespace gdt
{
  /**
   * @brief Class corresponding to the %quest_item_t schema type.
   *
   * @nosubgrouping
   */
  class GIDEON_CS_API quest_item_t: public ::xml_schema::type
  {
    public:
    /**
     * @name quest_item_code
     *
     * @brief Accessor and modifier functions for the %quest_item_code
     * required attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::xml_schema::unsigned_int quest_item_code_type;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< quest_item_code_type, wchar_t > quest_item_code_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const quest_item_code_type&
    quest_item_code () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    quest_item_code_type&
    quest_item_code ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    quest_item_code (const quest_item_code_type& x);

    //@}

    /**
     * @name looting_mil_sec
     *
     * @brief Accessor and modifier functions for the %looting_mil_sec
     * required attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::xml_schema::unsigned_int looting_mil_sec_type;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< looting_mil_sec_type, wchar_t > looting_mil_sec_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const looting_mil_sec_type&
    looting_mil_sec () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    looting_mil_sec_type&
    looting_mil_sec ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    looting_mil_sec (const looting_mil_sec_type& x);

    //@}

    /**
     * @name stack_count
     *
     * @brief Accessor and modifier functions for the %stack_count
     * required attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::xml_schema::unsigned_byte stack_count_type;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< stack_count_type, wchar_t > stack_count_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const stack_count_type&
    stack_count () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    stack_count_type&
    stack_count ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    stack_count (const stack_count_type& x);

    //@}

    /**
     * @name usable_count
     *
     * @brief Accessor and modifier functions for the %usable_count
     * required attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::xml_schema::unsigned_byte usable_count_type;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< usable_count_type, wchar_t > usable_count_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const usable_count_type&
    usable_count () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    usable_count_type&
    usable_count ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    usable_count (const usable_count_type& x);

    //@}

    /**
     * @name skill_code
     *
     * @brief Accessor and modifier functions for the %skill_code
     * required attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::gdt::any_skill_code_t skill_code_type;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< skill_code_type, wchar_t > skill_code_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const skill_code_type&
    skill_code () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    skill_code_type&
    skill_code ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    skill_code (const skill_code_type& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    skill_code (::std::unique_ptr< skill_code_type > p);

    //@}

    /**
     * @name icon_name
     *
     * @brief Accessor and modifier functions for the %icon_name
     * required attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::xml_schema::string icon_name_type;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< icon_name_type, wchar_t > icon_name_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const icon_name_type&
    icon_name () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    icon_name_type&
    icon_name ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    icon_name (const icon_name_type& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    icon_name (::std::unique_ptr< icon_name_type > p);

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Default constructor.
     *
     * Note that this constructor leaves required elements and
     * attributes uninitialized.
     */
    quest_item_t ();

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    quest_item_t (const quest_item_code_type&,
                  const looting_mil_sec_type&,
                  const stack_count_type&,
                  const usable_count_type&,
                  const skill_code_type&,
                  const icon_name_type&);

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    quest_item_t (const ::xercesc::DOMElement& e,
                  ::xml_schema::flags f = 0,
                  ::xml_schema::container* c = 0);

    /**
     * @brief Copy constructor.
     *
     * @param x An instance to make a copy of.
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     *
     * For polymorphic object models use the @c _clone function instead.
     */
    quest_item_t (const quest_item_t& x,
                  ::xml_schema::flags f = 0,
                  ::xml_schema::container* c = 0);

    /**
     * @brief Copy the instance polymorphically.
     *
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     * @return A pointer to the dynamically allocated copy.
     *
     * This function ensures that the dynamic type of the instance is
     * used for copying and should be used for polymorphic object
     * models instead of the copy constructor.
     */
    virtual quest_item_t*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    /**
     * @brief Copy assignment operator.
     *
     * @param x An instance to make a copy of.
     * @return A reference to itself.
     *
     * For polymorphic object models use the @c _clone function instead.
     */
    quest_item_t&
    operator= (const quest_item_t& x);

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~quest_item_t ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< wchar_t >&,
           ::xml_schema::flags);

    protected:
    ::xsd::cxx::tree::one< quest_item_code_type > quest_item_code_;
    ::xsd::cxx::tree::one< looting_mil_sec_type > looting_mil_sec_;
    ::xsd::cxx::tree::one< stack_count_type > stack_count_;
    ::xsd::cxx::tree::one< usable_count_type > usable_count_;
    ::xsd::cxx::tree::one< skill_code_type > skill_code_;
    ::xsd::cxx::tree::one< icon_name_type > icon_name_;

    //@endcond
  };

  /**
   * @brief Class corresponding to the %quest_item_table schema type.
   *
   * @nosubgrouping
   */
  class GIDEON_CS_API quest_item_table: public ::xml_schema::type
  {
    public:
    /**
     * @name quest_item_template
     *
     * @brief Accessor and modifier functions for the %quest_item_template
     * sequence element.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::gdt::quest_item_t quest_item_template_type;

    /**
     * @brief Element sequence container type.
     */
    typedef ::xsd::cxx::tree::sequence< quest_item_template_type > quest_item_template_sequence;

    /**
     * @brief Element iterator type.
     */
    typedef quest_item_template_sequence::iterator quest_item_template_iterator;

    /**
     * @brief Element constant iterator type.
     */
    typedef quest_item_template_sequence::const_iterator quest_item_template_const_iterator;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< quest_item_template_type, wchar_t > quest_item_template_traits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * sequence.
     *
     * @return A constant reference to the sequence container.
     */
    const quest_item_template_sequence&
    quest_item_template () const;

    /**
     * @brief Return a read-write reference to the element sequence.
     *
     * @return A reference to the sequence container.
     */
    quest_item_template_sequence&
    quest_item_template ();

    /**
     * @brief Copy elements from a given sequence.
     *
     * @param s A sequence to copy elements from.
     *
     * For each element in @a s this function makes a copy and adds it 
     * to the sequence. Note that this operation completely changes the 
     * sequence and all old elements will be lost.
     */
    void
    quest_item_template (const quest_item_template_sequence& s);

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    quest_item_table ();

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    quest_item_table (const ::xercesc::DOMElement& e,
                      ::xml_schema::flags f = 0,
                      ::xml_schema::container* c = 0);

    /**
     * @brief Copy constructor.
     *
     * @param x An instance to make a copy of.
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     *
     * For polymorphic object models use the @c _clone function instead.
     */
    quest_item_table (const quest_item_table& x,
                      ::xml_schema::flags f = 0,
                      ::xml_schema::container* c = 0);

    /**
     * @brief Copy the instance polymorphically.
     *
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     * @return A pointer to the dynamically allocated copy.
     *
     * This function ensures that the dynamic type of the instance is
     * used for copying and should be used for polymorphic object
     * models instead of the copy constructor.
     */
    virtual quest_item_table*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    /**
     * @brief Copy assignment operator.
     *
     * @param x An instance to make a copy of.
     * @return A reference to itself.
     *
     * For polymorphic object models use the @c _clone function instead.
     */
    quest_item_table&
    operator= (const quest_item_table& x);

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~quest_item_table ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< wchar_t >&,
           ::xml_schema::flags);

    protected:
    quest_item_template_sequence quest_item_template_;

    //@endcond
  };
}

#ifndef XSD_DONT_INCLUDE_INLINE

#include "shared_types.ixx"

#endif // XSD_DONT_INCLUDE_INLINE

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

namespace gdt
{
  /**
   * @name Parsing functions for the %quest_item_table document root.
   */
  //@{

  /**
   * @brief Parse a URI or a local file.
   *
   * @param uri A URI or a local file name.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function uses exceptions to report parsing errors.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::quest_item_table >
  quest_item_table_ (const ::std::wstring& uri,
                     ::xml_schema::flags f = 0,
                     const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a URI or a local file with an error handler.
   *
   * @param uri A URI or a local file name.
   * @param eh An error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::quest_item_table >
  quest_item_table_ (const ::std::wstring& uri,
                     ::xml_schema::error_handler& eh,
                     ::xml_schema::flags f = 0,
                     const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a URI or a local file with a Xerces-C++ DOM error
   * handler.
   *
   * @param uri A URI or a local file name.
   * @param eh A Xerces-C++ DOM error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::quest_item_table >
  quest_item_table_ (const ::std::wstring& uri,
                     ::xercesc::DOMErrorHandler& eh,
                     ::xml_schema::flags f = 0,
                     const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream.
   *
   * @param is A standrad input stream.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function uses exceptions to report parsing errors.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::quest_item_table >
  quest_item_table_ (::std::istream& is,
                     ::xml_schema::flags f = 0,
                     const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream with an error handler.
   *
   * @param is A standrad input stream.
   * @param eh An error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::quest_item_table >
  quest_item_table_ (::std::istream& is,
                     ::xml_schema::error_handler& eh,
                     ::xml_schema::flags f = 0,
                     const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream with a Xerces-C++ DOM error
   * handler.
   *
   * @param is A standrad input stream.
   * @param eh A Xerces-C++ DOM error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::quest_item_table >
  quest_item_table_ (::std::istream& is,
                     ::xercesc::DOMErrorHandler& eh,
                     ::xml_schema::flags f = 0,
                     const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream with a resource id.
   *
   * @param is A standrad input stream.
   * @param id A resource id.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * The resource id is used to identify the document being parsed in
   * diagnostics as well as to resolve relative paths.
   *
   * This function uses exceptions to report parsing errors.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::quest_item_table >
  quest_item_table_ (::std::istream& is,
                     const ::std::wstring& id,
                     ::xml_schema::flags f = 0,
                     const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream with a resource id and an
   * error handler.
   *
   * @param is A standrad input stream.
   * @param id A resource id.
   * @param eh An error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * The resource id is used to identify the document being parsed in
   * diagnostics as well as to resolve relative paths.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::quest_item_table >
  quest_item_table_ (::std::istream& is,
                     const ::std::wstring& id,
                     ::xml_schema::error_handler& eh,
                     ::xml_schema::flags f = 0,
                     const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream with a resource id and a
   * Xerces-C++ DOM error handler.
   *
   * @param is A standrad input stream.
   * @param id A resource id.
   * @param eh A Xerces-C++ DOM error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * The resource id is used to identify the document being parsed in
   * diagnostics as well as to resolve relative paths.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::quest_item_table >
  quest_item_table_ (::std::istream& is,
                     const ::std::wstring& id,
                     ::xercesc::DOMErrorHandler& eh,
                     ::xml_schema::flags f = 0,
                     const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a Xerces-C++ input source.
   *
   * @param is A Xerces-C++ input source.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function uses exceptions to report parsing errors.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::quest_item_table >
  quest_item_table_ (::xercesc::InputSource& is,
                     ::xml_schema::flags f = 0,
                     const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a Xerces-C++ input source with an error handler.
   *
   * @param is A Xerces-C++ input source.
   * @param eh An error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::quest_item_table >
  quest_item_table_ (::xercesc::InputSource& is,
                     ::xml_schema::error_handler& eh,
                     ::xml_schema::flags f = 0,
                     const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a Xerces-C++ input source with a Xerces-C++ DOM
   * error handler.
   *
   * @param is A Xerces-C++ input source.
   * @param eh A Xerces-C++ DOM error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::quest_item_table >
  quest_item_table_ (::xercesc::InputSource& is,
                     ::xercesc::DOMErrorHandler& eh,
                     ::xml_schema::flags f = 0,
                     const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a Xerces-C++ DOM document.
   *
   * @param d A Xerces-C++ DOM document.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::quest_item_table >
  quest_item_table_ (const ::xercesc::DOMDocument& d,
                     ::xml_schema::flags f = 0,
                     const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a Xerces-C++ DOM document.
   *
   * @param d A pointer to the Xerces-C++ DOM document.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function is normally used together with the keep_dom and
   * own_dom parsing flags to assign ownership of the DOM document
   * to the object model.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::quest_item_table >
  quest_item_table_ (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
                     ::xml_schema::flags f = 0,
                     const ::xml_schema::properties& p = ::xml_schema::properties ());

  //@}
}

#include <iosfwd>

#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>
#include <xercesc/framework/XMLFormatter.hpp>

#include <xsd/cxx/xml/dom/auto-ptr.hxx>

namespace gdt
{
  /**
   * @name Serialization functions for the %quest_item_table document root.
   */
  //@{

  /**
   * @brief Serialize to a standard output stream.
   *
   * @param os A standrad output stream.
   * @param x An object model to serialize.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function uses exceptions to report serialization errors.
   */
  GIDEON_CS_API
  void
  quest_item_table_ (::std::ostream& os,
                     const ::gdt::quest_item_table& x, 
                     const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                     const ::std::wstring& e = L"UTF-8",
                     ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a standard output stream with an error handler.
   *
   * @param os A standrad output stream.
   * @param x An object model to serialize.
   * @param eh An error handler.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function reports serialization errors by calling the error
   * handler.
   */
  GIDEON_CS_API
  void
  quest_item_table_ (::std::ostream& os,
                     const ::gdt::quest_item_table& x, 
                     ::xml_schema::error_handler& eh,
                     const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                     const ::std::wstring& e = L"UTF-8",
                     ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a standard output stream with a Xerces-C++ DOM
   * error handler.
   *
   * @param os A standrad output stream.
   * @param x An object model to serialize.
   * @param eh A Xerces-C++ DOM error handler.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function reports serialization errors by calling the error
   * handler.
   */
  GIDEON_CS_API
  void
  quest_item_table_ (::std::ostream& os,
                     const ::gdt::quest_item_table& x, 
                     ::xercesc::DOMErrorHandler& eh,
                     const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                     const ::std::wstring& e = L"UTF-8",
                     ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a Xerces-C++ XML format target.
   *
   * @param ft A Xerces-C++ XML format target.
   * @param x An object model to serialize.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function uses exceptions to report serialization errors.
   */
  GIDEON_CS_API
  void
  quest_item_table_ (::xercesc::XMLFormatTarget& ft,
                     const ::gdt::quest_item_table& x, 
                     const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                     const ::std::wstring& e = L"UTF-8",
                     ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a Xerces-C++ XML format target with an error
   * handler.
   *
   * @param ft A Xerces-C++ XML format target.
   * @param x An object model to serialize.
   * @param eh An error handler.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function reports serialization errors by calling the error
   * handler.
   */
  GIDEON_CS_API
  void
  quest_item_table_ (::xercesc::XMLFormatTarget& ft,
                     const ::gdt::quest_item_table& x, 
                     ::xml_schema::error_handler& eh,
                     const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                     const ::std::wstring& e = L"UTF-8",
                     ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a Xerces-C++ XML format target with a
   * Xerces-C++ DOM error handler.
   *
   * @param ft A Xerces-C++ XML format target.
   * @param x An object model to serialize.
   * @param eh A Xerces-C++ DOM error handler.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function reports serialization errors by calling the error
   * handler.
   */
  GIDEON_CS_API
  void
  quest_item_table_ (::xercesc::XMLFormatTarget& ft,
                     const ::gdt::quest_item_table& x, 
                     ::xercesc::DOMErrorHandler& eh,
                     const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                     const ::std::wstring& e = L"UTF-8",
                     ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to an existing Xerces-C++ DOM document.
   *
   * @param d A Xerces-C++ DOM document.
   * @param x An object model to serialize.
   * @param f Serialization flags.
   *
   * Note that it is your responsibility to create the DOM document
   * with the correct root element as well as set the necessary
   * namespace mapping attributes.
   */
  GIDEON_CS_API
  void
  quest_item_table_ (::xercesc::DOMDocument& d,
                     const ::gdt::quest_item_table& x,
                     ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a new Xerces-C++ DOM document.
   *
   * @param x An object model to serialize.
   * @param m A namespace information map.
   * @param f Serialization flags.
   * @return A pointer to the new Xerces-C++ DOM document.
   */
  GIDEON_CS_API
  ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
  quest_item_table_ (const ::gdt::quest_item_table& x, 
                     const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                     ::xml_schema::flags f = 0);

  //@}

  GIDEON_CS_API
  void
  operator<< (::xercesc::DOMElement&, const quest_item_t&);

  GIDEON_CS_API
  void
  operator<< (::xercesc::DOMElement&, const quest_item_table&);
}

#ifndef XSD_DONT_INCLUDE_INLINE
#include "quest_item_table.ixx"
#endif // XSD_DONT_INCLUDE_INLINE

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // GDT_QUEST_ITEM_TABLE_HXX
